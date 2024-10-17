#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main()
{

    // Let's declare a winsize struct to store the window size. This struct is defined in sys/ioctl.h
    struct winsize w;

    // Let's open the terminal device file /dev/tty using the open system call, passing in the O_RDONLY flag to open the file for reading
    int fd = open("/dev/tty", O_RDONLY);

    // Next let's check if the file was opened successfully
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Next let's use the ioctl system call to get the window size of the terminal
    if (ioctl(fd, TIOCGWINSZ, &w) == -1)
    {
        perror("ioctl");
        close(fd);
        return 1;
    }

    // Finally, let's print out the number of rows and columns in the terminal window

    printf("Rows: %d, Columns: %d\n", w.ws_row, w.ws_col);

    close(fd);
    return 0;
}