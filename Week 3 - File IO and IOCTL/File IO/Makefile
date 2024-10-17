CC = g++
CFLAGS=-I.
CFLAGS+=-Wall
CFLAGS+=-c

# Link CopyText.o with the standard C++ library
CopyText: CopyText.o
	$(CC) -o CopyText CopyText.o

# Compile CopyTextcpp to CopyText.o
CopyText.o: CopyText.cpp
	$(CC) $(CFLAGS) CopyText.cpp

# Clean up the object files and executable
clean:
	rm -f *.o CopyText copy.txt


