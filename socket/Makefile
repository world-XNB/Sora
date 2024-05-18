CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = client
SRCS = client.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS): $(wildcard ../include/*.h)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean