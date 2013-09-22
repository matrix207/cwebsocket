################################################################################
# Makefile
# History:
#     2013/09/22 Dennis Create
################################################################################

include ../Make.defines

#LIB_OBJS = base64_enc.o sha1.o websocket.o
# auto generate object name
LIB_PATH = $(shell pwd)
OBJ_SRCS := $(notdir $(shell find $(LIB_PATH) -maxdepth 1 -name '*.c'))
LIB_OBJS := $(OBJ_SRCS:.c=.o)

all: ${LIB_OBJS}
	ar rv ${LIBWEBSOCKET_NAME} $?

.PHONY: clean
clean:
	rm -f ${PROGS} ${CLEANFILES}
