*This project has been created as part of the 42 curriculum by niebais.*

## Description

A function that reads one line at a time from a file descriptor.

## Usage
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## How It Works

Three steps each call:
1. Read chunks from file until we find a newline
2. Extract and return that line
3. Save leftovers in static variable for next time

## Resources

- Linux man pages (read, open)
- Tested with francinette and valgrind
- The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie

## AI Usage

AI tools (Claude) were used for:

- Understanding static variables
- Clarifying memory leaks
- Improving README structure

No AI was used to generate the final implementation code.
All logic was written and understood by the author.
