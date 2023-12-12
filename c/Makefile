CC= gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -Wvla -Werror -pedantic -std=c99
LDFLAGS=
LDLIBS=

DAY= day0
SRC= ${DAY}.c

all: debug

${DAY}: ${SRC}

debug: CFLAGS += -fsanitize=address -g3
debug: ${DAY}

release: CFLAGS += -O2
release: ${DAY}

clean:
	${RM} ${DAY}

.PHONY: debug release clean
