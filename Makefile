SRC = parse_json.c print_matrix.c main.c
CC ?= gcc
BIN ?= tty-mars

CFLAGS += -Wall -g $$(pkg-config --cflags ncurses) $$(pkg-config --cflags json-c)
LDFLAGS += $$(pkg-config --libs ncurses) $$(pkg-config --libs json-c)

tty-mars : ${SRC}
	@echo "building ${SRC}"
	${CC} ${CFLAGS} ${SRC} -o ${BIN} ${LDFLAGS}
	@rm -f *.o