#
# Remember, you use pound signs for comments in makefiles!
#

# Start with your compilation variables

CC = g++
CFLAGS = -g -Wall -Wextra

# simply calling 'make' will invoke the default!

default: stacker

# Rule for stacker
stacker: Stacker.o main.o
	$(CC) $(CFLAGS) -o stacker Stacker.o main.o

# Rule for stacker
Stacker.o: Stacker.cpp Stacker.h
	$(CC) $(CFLAGS) -c Stacker.cpp

#Rule for main
main.o: main.cpp Stacker.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) stacker *.o *~
