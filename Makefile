all: rodcut

OBJS = rodcut.o vec.o piece_values.o cut_list.o
CC = gcc
CFLAGS = -Wall -g

rodcut: $(OBJS)
	gcc -o a.out $(CFLAGS) $(OBJS) -lm

rodcut.o: rodcut.c vec.h piece_values.h

vec.o: vec.c vec.h

piece_values.o: piece_values.c piece_values.h

cut_list.o: cut_list.c cut_list.h

clean:
	rm -f a.out $(OBJS)
