CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

OBJS = fifo.o

.PHONY: all clean

all: library

$(NAME): library

$(OBJ): fifo.c
	gcc $(CFLAFS) -c $^ -o $@
library: $(OBJS)
	ar -csr libfifo.a fifo.o
clean:
	$(RM) -f *.o *.a fifo
