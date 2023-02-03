CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ = main.o startgame.o initialisation.o random.o populater.o movement.o arrays.o terminal.o
EXEC = snake

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
UNBEATABLE	:	clean $(EXEC)
endif

$(EXEC)	:	$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o	:	main.c startgame.h
	$(CC) -c main.c $(CFLAGS)	

startgame.o	:	startgame.c initialisation.h populater.h movement.h arrays.h startgame.h macros.h terminal.h
	$(CC) -c startgame.c $(CFLAGS)

initialisation.o	:	initialisation.c initialisation.h macros.h random.h
	$(CC) -c initialisation.c $(CFLAGS)

populater.o	:	populater.c populater.h initialisation.h
	$(CC) -c populater.c $(CFLAGS)

movement.o	:	movement.c	movement.h arrays.h populater.h startgame.h
	$(CC) -c movement.c $(CFLAGS)

random.o	:	random.c random.h
	$(CC) -c random.c $(CFLAGS)

arrays.o	: arrays.c arrays.h
	$(CC) -c arrays.c $(CFLAGS)

terminal.o	: terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)