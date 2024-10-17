# Week 2 Content Notes

## Legend

Likely Unimportant - 🟦

Likely Important - 🟩

Very Important - 🟥

## Topics

### Static Libraries

#### Important Commands for Static Libraries (from the textbook readings on static libraries)

##### Creating a **static library**:

`$ ar options archive object-file...`

**Options:**

-   r (replace): Insert an object file into the archive, replacing any previous object
    file of the same name.

-   t (table of contents): Display a table of contents of the archive. By default, this
    lists just the names of the object files in the archive. By adding the v (verbose)
    modifier, we additionally see all of the other attributes recorded in the archive
    for each object file

-   d (delete): Delete a named module from the archive

-   Example:
    `$ gcc -c cfile1.c cfile2.c cfile3.c` Compile your C files

`$ ar -r libdemo.a cfile1.o cfile2.o cfile3.o` This will create the libdemo.a static lib if it doesn't already exist and add the 3 object files, removing any duplicates

`$ rm cfile1.o cfile2.o cfile3.o` You can delete the object files once they are added to the library

##### Using a Static Library

We can link a program against a static library in two ways. The first is to name the
static library as part of the link command, as in the following:

`$ gcc -c program.c` Compile the program

`$ gcc -o program program.o libdemo.a` Link the programs object file ot the library when creating the runnable executable

Alternatively, we can place the library in one of the standard directories searched
by the linker (e.g., /usr/lib), and then specify the library name (i.e., the filename of
the library without the lib prefix and .a suffix) using the –l option:

`$ gcc -c program.c`

`$ gcc -o program program.o -ldemo`

If the library resides in a directory not normally searched by the linker, we can
specify that the linker should search this additional directory using the –L option:

`$ gcc -o program program.o -Lmylibdir -ldemo`

### Shared Libraries

##### Creating and using a **shared library**:

1. `$ gcc -shared -o libdemo.so cfile1.o cfile2.o cfile3.o` This will create the shared library libdemo.so from the object files
2. Now that the library is created we need to install it to the lib folder so that the linker can find it
    - `$ cp libdemo.so /usr/lib` Copy the shared library to the /usr/lib directory
3. We need to update the linker cache so that the linker can find the library
    - `$ ldconfig` Update the linker cache
4. Now we can link our program against the shared library
    - `$ gcc -o program program.o -ldemo` Link the program against the shared library
5. Special case
    - If the shared library is not in a standard directory, we can specify the directory using the -L option
    - `$ gcc -o program program.o -Lmylibdir -ldemo`
