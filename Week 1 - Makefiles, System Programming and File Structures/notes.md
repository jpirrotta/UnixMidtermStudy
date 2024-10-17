# Week 1 Content Notes

## Legend

Likely Unimportant - 🟦

Likely Important - 🟩

Very Important - 🟥

## Topics

-   [Linux History](#linux-history) - 🟦
-   [Linux File System](#linux-file-system) - 🟩
-   [Common Linux Commmands](#common-linux-commands) - 🟦
-   [System Programming](#system-programming) - 🟩
-   [Makefiles](#makefiles) - 🟦/🟩

### Linux History

#### Unix Origins

-   Emerged from the Multics project at Bell Labs in the late 1960s
-   Ken Thompson and Dennis Ritchie were key developers
-   Rewritten in C language in 1972-73, enhancing portability

#### Unix Evolution

-   AT&T's Unix System Laboratories continued development
-   University of California Berkeley created BSD (Berkeley Software Distribution)
-   Commercial Unix versions emerged from these efforts

#### Free Software Movement

-   Richard Stallman initiated the GNU project in 1984
-   Aimed to create a non-proprietary Unix-like system

#### Linux Emergence

-   Linus Torvalds announced his project in 1991
-   Developed as an alternative to MINIX
-   Linux kernel 1.0 released in 1994

#### Key Distinctions

-   Linux is not a Unix derivative, but was written from scratch
-   Linux shares many commands and principles with Unix
-   Linux became a free, open-source alternative to proprietary Unix systems

### Linux File System

#### Directories

##### /bin

-   Contains essential system binaries
-   ls command is here as well as other basic programs and tools for file manipulation (editing, moving etc.)

##### /boot

-   Contains files needed to boot the system
-   Don't mess with this directory unless you know what you're doing

##### /dev

-   Contains device files
-   Many are generated at boot time or on the fly
-   If you plug in a USB drive, a device file will be created here

##### /etc

-   Contains system-wide configuration files
-   Stuff like network configuration, user account information, etc.
-

##### /home

-   Users personal directories are here

##### /lib

-   Library files are here
-   Library files may be in other places as well
-   This is the all important one though that holds kernel modules and other stuff like that

##### /media

-   External storage devices are automatically mounted here

##### /mnt

-   Where you would manually mount storage devices or partitions
-   Not used much anymore

##### /opt

-   Where most compiled software (software you built yourself from source code) sometimes shows up
-   /usr/local is another place where these files could end up but its dependent on the developers configurations
-

##### /proc

-   Contains information about system processes
-   This is a virtual file system that is created on the fly

##### /root

-   The root user's home directory
-   The root user is the super user and has access to everything
-   Separate from the /home directory because you shouldn't be using the root user for everyday tasks or storing stuff, use your own!

##### /run

-   System process store temp data here, don't mess with it

##### /sbin

-   Contains system binaries that are only used by the super user
-   Stuff in here needs sudo to be ran

##### /usr

-   Used to be what the /home directory is now
-   Now it contains user binaries and libraries
-   /bin and /sbin are actually linked to /usr/bin and /usr/sbin respectively on most modern distros

##### /srv

-   Contains data for servers
-   Stuff like websites, ftp servers, etc.

##### /sys

-   Contains information about devices connected to the system
-   This is a virtual file system that is created on the fly like /proc and /dev

##### /tmp

-   Temporary files are stored here
-   You can actually store files you want to be temporary here
-   One of the few directories hanging off the root that you can access without sudo

##### /var

-   Stores files that change frequently
-   Log files and the sort

### Common Linux Commands

-   `nm` - List symbols from object files
    -   commonly used to see what symbols are in a static library
-   `ldd` - Print shared library dependencies
    -   used to see what shared libraries an executable depends on
-   `top` - Display Linux processes
    -   used to see what processes are running on your system
-   `netstat` - Print network connections
-   `tail -f` - Output appended data as the file grows
    -   used to watch a file as it grows
-   `cd` - Change directory
-   `ls` - List directory contents
-   `pwd` - Print working directory
-   `cp` - Copy files and directories
-   `mv` - Move files and directories
-   `rm` - Remove files and directories
-   `mkdir` - Make directories
-   `rmdir` - Remove directories
-   `cat` - Concatenate files and print on the standard output
-   `grep` - Print lines matching a pattern
-   `nano` - Text editor
-   `vim` - Text editor
-   `uname` - Print system information

### System Programming

#### System Calls

-   What is a system call?
    -   A system call is a controlled entry point into the kernel.
    -   In C programming you typically make system call by calling a function which wraps the system call.
-   What is an example of a system call?
    -   `open()` is a system call that opens a file.
    -   `read()` is a system call that reads from a file.
-   Error Handling
    -   If there are any errors when making a system call, the variable `errno` is set to a value that corresponds to the error that occurred.
    -   You can use the `perror()` function to print out the error message that corresponds to the value of `errno`.
    -   You can also use the `strerror()` function to get the error message as a string.

### Makefiles

-   [Makefiles with Variables](/Makefile%20Examples/With%20Variables/Makefile)
-   [Makefiles without Variables](/Makefile%20Examples/Without%20Variables/Makefile)
