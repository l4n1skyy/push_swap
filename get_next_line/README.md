*This project has been created as part of the 42 curriculum by lanusri-.*

# Description

get_next_line is a function that reads a file and returns it one line at a time each time the function is called.

# Instructions

Compilation (define `BUFFER_SIZE`):
  ```
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
  ```

Function Usage:
```c
  fd = open("file.txt", O_RDONLY);
  while ((line = get_next_line(fd)) != NULL)
  {
    printf("%s", line);
    free(line);
  }
  close(fd);
  ```

### Return Value:
- A line including the trailing \n
    - when the line read ends with a newline character in the file
- The final line with no trailing \n
    - when it's the last line in the file and the file doesn't end in a newline
- NULL
    - when there's nothing left to read (clean EOF, nothing more in the file), or when fd is invalid, or BUFFER_SIZE <= 0

### Parameters:
- file descriptor

### Files:
  - get_next_line.h: prototypes, BUFFER_SIZE fallback, includes
  - get_next_line.c: core logic, read loop, stash management, line splitting
  - get_next_line_utils.c: reimplemented libc helpers

# Algorithm

- A static char *stash persists between calls and holds whatever has been read but not yet returned
- On each call, if stash doesn't already contain a newline, the function reads BUFFER_SIZE chunks and appends them to stash, stopping when a newline appears in the newly read chunk, or read() returns 0 (EOF) or -1 (error)
- Once a newline is present, or EOF is reached, stash is split into the line to return and the remainder, which becomes the new stash
- If stash already contains a full line at the start of a call (because a previous read pulled in more than one line), no further read() happens, the line is served directly from stash
- The newline check is done on the newly read chunk rather than the whole stash, since re-scanning the whole accumulated stash on every loop pass repeats work already done on previous passes; checking only the small fixed-size chunk keeps that check cheap regardless of how large the line being built is

# Resources

- read(2) man page: https://man7.org/linux/man-pages/man2/read.2.html
- 42 School subject PDF for get_next_line (internal, not publicly linked)

# AI usage

- Claude was used for debugging and code-review only, not used as code generator.