CC=gcc
CFLAGS=-I -Wall -Wextra -Werror -pthread
DEPS=sum_array.h test_driver.h tests.h utils.h
OBJ=sum_array.o test_driver.o tests.o utils.o

%o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)