package = "suspend"
version = "scm-1"

source = {
    url = "git://github.com/1nv1/lua_suspend.git",
}

description = {
    summary = "Suspend function",
    detailed = [[
        Implements a suspend function based on sleep function of luasocket.
    ]],
    homepage = "https://github.com/1nv1/lua_suspend",
    license = "MIT/LuaSocket",
}

dependencies = {
    "lua >= 5.2",
}

build = {
    type = "builtin",
    modules = {
        suspend = "src/suspend.c",
    }
}