CFLAGS := -I. -I./include
SRC := $(wildcard ./src/*.c)
PROG := $(patsubst %.c,%,$(SRC))
CC := gcc
all: $(SRC)
	$(CC) $(CFLAGS) $^ -o ./out/$@


test_hiragana: test_hiragana.c hiragana.c
	$(CC) $(CFLAGS) $^ -o $@

test_xwrd_util: test_xwrd_util.c xwrd_util.c xwrd.c hiragana.c
	$(CC) $(CFLAGS) $^ -o $@
test_xwrd: test_xwrd.c xwrd_util.c xwrd.c hiragana.c
	$(CC) $(CFLAGS) $^ -o $@
clean:
	@$(RM) $(PROG)