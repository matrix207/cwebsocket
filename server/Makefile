################################################################################
# Makefile
# History:
#     2013/09/22 Dennis Create
################################################################################

include ../Make.defines

PROGS = demo

all: ${PROGS}

${PROGS}: main.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

.PHONY: clean
clean:
	rm -f ${PROGS} ${CLEANFILES}
