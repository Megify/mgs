bin_PROGRAMS = mgs
mgs_SOURCES  = src/main.c \
               src/backend.c \
               src/interface.c \
               src/mgs.c \
               src/sdl.c
mgs_CPPFLAGS = @SDL2_CFLAGS@
mgs_LDFLAGS  = @SDL2_LIBS@

check_PROGRAMS = test1
test1_SOURCES  = test/test1.c
test1_CPPFLAGS = @CHECK_CFLAGS@
test1_LDFLAGS  = @CHECK_LIBS@

TESTS = $(check_PROGRAMS)

man_MANS = mgs.1
