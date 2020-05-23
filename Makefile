SRC = print_matrix.c main.c
CC ?= gcc
BIN ?= tty-mars

ifeq ($(shell sh -c 'which ncurses6-config>/dev/null 2>/dev/null && echo y'), y)
	CFLAGS += -Wall -g $$(ncurses6-config --cflags)
	LDFLAGS += $$(ncurses6-config --libs)
else ifeq ($(shell sh -c 'which ncursesw6-config>/dev/null 2>/dev/null && echo y'), y)
	CFLAGS += -Wall -g $$(ncursesw6-config --cflags)
	LDFLAGS += $$(ncursesw6-config --libs)
else ifeq ($(shell sh -c 'which ncurses5-config>/dev/null 2>/dev/null && echo y'), y)
	CFLAGS += -Wall -g $$(ncurses5-config --cflags)
	LDFLAGS += $$(ncurses5-config --libs)
else ifeq ($(shell sh -c 'which ncursesw5-config>/dev/null 2>/dev/null && echo y'), y)
	CFLAGS += -Wall -g $$(ncursesw5-config --cflags)
	LDFLAGS += $$(ncursesw5-config --libs)
else
	CFLAGS += -Wall -g $$(pkg-config --cflags ncurses)
	LDFLAGS += $$(pkg-config --libs ncurses)
endif

tty-mars : ${SRC}
	@echo "building ${SRC}"
	${CC} ${CFLAGS} ${SRC} -o ${BIN} ${LDFLAGS}
	@rm -f *.o