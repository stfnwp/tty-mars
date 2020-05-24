SRC = get.c get_weather.c print_matrix.c main.c
CC ?= gcc
BIN ?= tty-mars

CFLAGS += -Wall -g $$(pkg-config --cflags ncurses) $$(pkg-config --cflags json-c) $$(pkg-config --cflags libcurl)
LDFLAGS += $$(pkg-config --libs ncurses) $$(pkg-config --libs json-c) $$(pkg-config --libs libcurl)

tty-mars : ${SRC}
	@echo "building ${SRC}"
	${CC} ${CFLAGS} ${SRC} -o ${BIN} ${LDFLAGS}
	@rm -f *.o