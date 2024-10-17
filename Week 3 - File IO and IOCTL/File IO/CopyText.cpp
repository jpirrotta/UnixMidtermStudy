/*
This program will copy the contents of one file to another file, skipping the first word of the file.

It is intended to show how to use open, read, write, lseek, and close system calls.

*/
#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main()
{
    // Let's declare some variables first

    int fdOriginal;          // This will be the file descriptor for the original file
    int fdCopy;              // This will be the file descriptor for the copy of the original file
    int bufferSize = 1024;   // This will be the size of the buffer we use to read the contents of the original file
    char buffer[bufferSize]; // This will be the buffer we use to read the contents of the original file
    ssize_t bytesRead;       // This will be the number of bytes read from the original file
    ssize_t bytesWritten;    // This will be the number of bytes written to the copy file

    // Let's open the original file using the open system call
    fdOriginal = open("original.txt", O_RDONLY);

    // Next lets check if the file was opened successfully
    if (fdOriginal == -1)
    {
        cout << "Error opening the original file" << endl;
        return 1;
    }
    else
    {
        // If the file was opened successfully, let's open the copy file
        // We pass in the O_WRONLY flag to open the file for writing and the O_CREAT flag to create the file if it doesn't exist
        // We also pass in the permissions for the file using the S_IRUSR, S_IWUSR, S_IRGRP, S_IWGRP, S_IROTH, S_IWOTH flags (these are rw for user, group, and others)
        fdCopy = open("copy.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

        // Next let's check if the file was opened successfully
        if (fdCopy == -1)
        {
            cout << "Error opening the copy file" << endl;
            return 1;
        }
        else
        {
            // Create a variable to track the bytes in the first word
            off_t offset = 0;

            // Let's read the original file until we reach a space or newline character indicating the end of the first word
            while (read(fdOriginal, buffer, 1) > 0 && buffer[0] != ' ' && buffer[0] != '\n')
            {
                offset++;
            }

            // Now we can skip past the first word (we do +1 to skip the space or newline character)
            lseek(fdOriginal, offset + 1, SEEK_SET); // Skip the space or newline after the first word

            // Now we can read the original file and write to the copy file. We will read the contents of the original file until there is nothing left to read
            while ((bytesRead = read(fdOriginal, buffer, bufferSize)) > 0)
            {
                // We will write the contents of the buffer to the screen
                bytesWritten = write(1, buffer, bytesRead);

                // We write the contents of the buffer to the copy file
                bytesWritten = write(fdCopy, buffer, bytesRead);

                // Let's check if the write was successful by comparing the number of bytes written to the number of bytes read
                if (bytesWritten != bytesRead)
                {
                    cout << "Error writing to the copy file" << endl;
                    return 1;
                }

                // By now the contents of the original file have been read and written to the copy file
            }

            // Let's close the original file
            close(fdOriginal);
            // Let's close the copy file
            close(fdCopy);
        }
    }
}