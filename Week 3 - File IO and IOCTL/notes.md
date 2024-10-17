### FILE I/O Important Functions

1. **`open`**

    - **Purpose**: Opens a file and returns a file descriptor.
    - **Prototype**: `int open(const char *pathname, int flags, mode_t mode);`
    - **Arguments**:
        - `pathname`: The name of the file to open.
        - `flags`: Specifies the access mode (e.g., `O_RDONLY`, `O_WRONLY`, `O_CREAT`).
        - `mode`: Specifies the file permissions if the file is created (e.g., `S_IRUSR`, `S_IWUSR`).
    - **Return Value**: Returns a file descriptor on success, or `-1` on error.

2. **`read`**

    - **Purpose**: Reads data from a file descriptor into a buffer.
    - **Prototype**: `ssize_t read(int fd, void *buf, size_t count);`
    - **Arguments**:
        - `fd`: The file descriptor to read from.
        - `buf`: The buffer where the read data will be stored.
        - `count`: The number of bytes to read.
    - **Return Value**: Returns the number of bytes read on success, `0` on end of file, or `-1` on error.

3. **`write`**

    - **Purpose**: Writes data from a buffer to a file descriptor.
    - **Prototype**: `ssize_t write(int fd, const void *buf, size_t count);`
    - **Arguments**:
        - `fd`: The file descriptor to write to.
        - `buf`: The buffer containing the data to write.
        - `count`: The number of bytes to write.
    - **Return Value**: Returns the number of bytes written on success, or `-1` on error.

4. **`close`**

    - **Purpose**: Closes a file descriptor.
    - **Prototype**: `int close(int fd);`
    - **Arguments**:
        - `fd`: The file descriptor to close.
    - **Return Value**: Returns `0` on success, or `-1` on error.

5. **`lseek`**
    - **Purpose**: Moves the file offset of a file descriptor.
    - **Prototype**: `off_t lseek(int fd, off_t offset, int whence);`
    - **Arguments**:
        - `fd`: The file descriptor to move the file offset of.
        - `offset`: The number of bytes to move the file offset by.
        - `whence`: Specifies the reference point for the offset (e.g., `SEEK_SET`, `SEEK_CUR`, `SEEK_END`).

### IOCTLs

**Basic Usage:**
`int ioctl(int fd, int request, additional device-specific and request specific arguments);`

-   `fd`: File descriptor of the device.
-   `request`: Request code number.

**Purpose:**

-   An ioctl() (input/output control) is a system call that provides a way to perform operations that fall outside the universal I/O model.

-   It allows performing device-specific operations that don't fit into the standard file I/O paradigm of open(), read(), write(), and close().
-   The ioctl() system call is typically used for:
    -   Controlling device behavior
    -   Retrieving information about a device
    -   Performing operations specific to certain types of files or devices
    -   ioctl() operations are often device-specific, meaning different devices or file types may support different ioctl commands.