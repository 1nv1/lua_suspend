#include <lua.h>
#include <lauxlib.h>

#ifdef _WIN32
#include <windows.h>
#define EXPORT __declspec(dllexport)
#else
#include <time.h>
#include <sys/time.h>
#define EXPORT
#endif

#ifdef _WIN32
static int lc_suspend(lua_State *L)
{
  double n = luaL_checknumber(L, 1);
  if (n < 0.0) n = 0.0;
  if (n < DBL_MAX/1000.0) n *= 1000.0;
  if (n > INT_MAX) n = INT_MAX;
  Sleep((int)n);
  return 0;
}
#else
static int lc_suspend(lua_State *L)
{
  double n = luaL_checknumber(L, 1);
  struct timespec t, r;
  if (n < 0.0) n = 0.0;
  if (n > INT_MAX) n = INT_MAX;
  t.tv_sec = (int) n;
  n -= t.tv_sec;
  t.tv_nsec = (int) (n * 1000000000);
  if (t.tv_nsec >= 1000000000) t.tv_nsec = 999999999;
  while (nanosleep(&t, &r) != 0) {
    t.tv_sec = r.tv_sec;
    t.tv_nsec = r.tv_nsec;
  }
  return 0;
}
#endif

EXPORT int luaopen_suspend(lua_State *L)
{
  lua_pushcfunction(L, lc_suspend);
  return 1;
}
