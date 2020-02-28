INCLUDES= -I/usr/local/include
LUA= lua
LIBFLAG= -shared -fpic
INSTALL= install -p
INSTALLPATH= $(LUA) installpath.lua

MODNAME= suspend
MODSO= $(MODNAME).so

all:$(MODSO)

suspend.so:	src/suspend.c
	$(CC) -o src/$(MODSO) $(LIBFLAG) $(CFLAGS) src/suspend.c $(INCLUDES) -llua

clean:
	$(RM) src/$(MODSO)

install: src/$(MODSO)
	$(INSTALL) $< `$(INSTALLPATH) $(MODNAME)`
