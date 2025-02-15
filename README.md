# Get Next Line

`get_next_line` is a C function that reads a line from a file descriptor, returning it as a string. It handles multiple file descriptors and reads efficiently using a buffer.

## Features

- Reads a line from a file descriptor.
- Supports multiple file descriptors simultaneously.
- Configurable buffer size for reading.

## Setup

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/jguigli/get_next_line.git
   cd get_next_line
   ```

2. **Compile the Code:**
   - Use the provided `Makefile` to compile the project.
   ```bash
   make
   ```

3. **Include Headers:**
   - Ensure your project includes `get_next_line.h` or `get_next_line_bonus.h` for the bonus version.

## Usage

1. **Function Signature:**
   ```c
   char *get_next_line(int fd);
   ```

2. **Basic Usage:**
   - Open a file and get its file descriptor.
   - Call `get_next_line(fd)` to read lines one by one.
   - Close the file descriptor after use.

   ```c
   #include "get_next_line.h"
   #include <fcntl.h>
   #include <stdio.h>

   int main(void)
   {
       int fd = open("file.txt", O_RDONLY);
       char *line;

       if (fd == -1)
           return (1);

       while ((line = get_next_line(fd)) != NULL)
       {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return (0);
   }
   ```

3. **Bonus Version:**
   - Supports reading from multiple file descriptors simultaneously.
   - Use `get_next_line_bonus.h` and `get_next_line_bonus.c`.

## Configuration

- **Buffer Size:**
  - Adjust `BUFFER_SIZE` in the header files (`get_next_line.h` or `get_next_line_bonus.h`) to optimize performance based on your needs.
