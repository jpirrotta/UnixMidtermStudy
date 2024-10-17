CC = g++
CFLAGS=-I.
CFLAGS+=-Wall
CFLAGS+=-c
ARFLAGS=rcs

# The executable is created by linking the object file with the static library
ProgramOutput: Program.o libtest.a
	$(CC) -o Program Program.o libtest.a

# The static library is created by archiving the object file
libtest.a: Message.o
	ar $(ARFLAGS) libtest.a Message.o
	rm Message.o

Program.o: Program.cpp
	$(CC) $(CFLAGS) Program.cpp

Message.o: Message.cpp
	$(CC) $(CFLAGS) Message.cpp

clean:
	rm -f *.o *.a Program