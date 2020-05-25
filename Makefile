SRC = get.c get_weather.c print_matrix.c main.c
CC ?= gcc
BIN ?= tty-mars

CFLAGS += -Wall -g $$(pkg-config --cflags ncurses) $$(pkg-config --cflags json-c) $$(pkg-config --cflags libcurl) $$(pkg-config --cflags glib-2.0)
LDFLAGS += $$(pkg-config --libs ncurses) $$(pkg-config --libs json-c) $$(pkg-config --libs libcurl) $$(pkg-config --libs glib-2.0)

tty-mars : ${SRC}
	@echo "building ${SRC}"
	${CC} ${CFLAGS} ${SRC} -o ${BIN} ${LDFLAGS}
	@rm -f *.o