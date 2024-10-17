# This is the same makefile as in Makefile Examples/Without Variables/Makefile but with variables for the compiler flags. There will be more makefile examples 
# in this repo and all will use the variables for flags so refer back here for an explanation if needed.

# * Variables are defined by VARNAME = value
# * Variables are referenced by $(VARNAME)

# This is the compiler flags variable, we are using gcc so we set it to gcc
CC = gcc
# This is the flags variable, we are using -I. to include the current directory in the search path
CFLAGS=-I.
# This is the flags variable, we are using -Wall to enable all warnings and the += append it to the variable
CFLAGS+=-Wall
# This is the flags variable, we are using -c to compile and not link and the += append it to the variable
CFLAGS+=-c

helloworldexec: helloworld.o
# Variables are referenced by $(VARNAME)
    $(CC) helloworld.o -o helloworld

helloworld.o: helloworld.c
# Variables are referenced by $(VARNAME)
    $(CC) $(CFLAGS) helloworld.c

clean:
    rm *.o helloworld