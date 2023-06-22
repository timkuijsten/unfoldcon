CFLAGS += -std=c17 -Wall -Wextra -pedantic-errors ${INCLUDES}

PREFIX = /usr/local
BINDIR = ${PREFIX}/bin

INSTALL_DIR = install -dm 755
INSTALL_BIN = install -m 0555

SRCFILES = unfoldcon.c

unfoldcon: unfoldcon.o
	${CC} ${CFLAGS} -o $@ unfoldcon.o

.SUFFIXES: .c .o
.c.o:
	${CC} ${CFLAGS} -c $<

lint:
	${CC} ${CFLAGS} -fsyntax-only ${SRCFILES} 2>&1

install:
	${INSTALL_DIR} ${DESTDIR}${BINDIR}
	${INSTALL_BIN} unfoldcon ${DESTDIR}${BINDIR}

clean:
	rm -f *.o unfoldcon
