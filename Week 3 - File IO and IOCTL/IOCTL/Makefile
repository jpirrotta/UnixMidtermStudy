CC = g++
CFLAGS=-I.
CFLAGS+=-Wall
CFLAGS+=-c

# Link terminalWindowSize.o with the standard C++ library
terminalWindowSize: terminalWindowSize.o
	$(CC) -o terminalWindowSize terminalWindowSize.o

# Compile terminalWindowSize.cpp to terminalWindowSize.o
terminalWindowSize.o: terminalWindowSize.cpp
	$(CC) $(CFLAGS) terminalWindowSize.cpp

# Clean up the object files and executable
clean:
	rm -f *.o terminalWindowSize