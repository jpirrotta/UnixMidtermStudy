CC = g++
CFLAGS = -I.
CFLAGS += -Wall
CFLAGS += -c
CFLAGS += -fPIC # Position Independent Code. This is required for shared libraries
ARFLAGS = rcs
LIBDIR = /usr/local/lib
LIBFLAGS = -shared
LIBFLAGS += -o

all: libtest.so createProg install runProg 

# First, we create the shared library by compiling the object file with the -fPIC flag
libtest.so: Message.o
	$(CC) $(LIBFLAGS) libtest.so Message.o

# We need to create the Message.o object file
Message.o: Message.cpp
	$(CC) $(CFLAGS) Message.cpp

# We then need to install the shared library in the system library directory and run ldconfig to update the library cache
install: libtest.so
	cp libtest.so $(LIBDIR)
	ldconfig


# We need to create the Program.o object file
createProg: Program.cpp
	$(CC) $(CFLAGS) Program.cpp

# We can now create the executable by linking the object file with the shared library
runProg: Program.o libtest.so
	$(CC) -o Program Program.o -L$(LIBDIR) -ltest

# Clean up the object files, shared library, and executable
clean:
	rm -f *.o *.so Program

