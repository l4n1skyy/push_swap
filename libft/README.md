*This project has been created as part of the 42 curriculum by lanusri-.*

# libft

## Description

My own version of functions from C standard library. Useful for understanding the implementation and also can be reused for future projects.

## Instructions

```bash
make
cc -Wall -Wextra -Werror main.c libft.a
```

- `make clean` — remove object files
- `make fclean` — remove object files + the lib
- `make re` — rebuild everything

## Resources

Checked function behavior against the C manual and asked peers to help understand better. Used AI to check edge cases and to also understand certain concepts better.

## Library

Split into three parts: basic libc functions, extended functions (split, itoa, iteration helpers, fd output), and linked list functions.
### Part 1

- `ft_isalpha` — check if char is alphabetic
- `ft_isdigit` — check if char is a digit
- `ft_isalnum` — check if char is alphanumeric
- `ft_isascii` — check if char is ASCII
- `ft_isprint` — check if char is printable
- `ft_strlen` — string length
- `ft_memset` — fill memory with a byte
- `ft_bzero` — zero out memory
- `ft_memcpy` — copy memory
- `ft_memmove` — copy memory, overlap-safe
- `ft_strlcpy` — bounded string copy
- `ft_strlcat` — bounded string concat
- `ft_toupper` — to uppercase
- `ft_tolower` — to lowercase
- `ft_strchr` — find first char occurrence
- `ft_strrchr` — find last char occurrence
- `ft_strncmp` — compare strings, n bytes
- `ft_memchr` — find byte in memory
- `ft_memcmp` — compare memory blocks
- `ft_strnstr` — find substring, bounded
- `ft_atoi` — string to int
- `ft_calloc` — zeroed allocation
- `ft_strdup` — duplicate a string

### Part 2

- `ft_substr` — get a substring
- `ft_strjoin` — join two strings
- `ft_strtrim` — trim chars off both ends
- `ft_split` — split by delimiter
- `ft_itoa` — int to string
- `ft_strmapi` — map function over string w/ index
- `ft_striteri` — apply function in place w/ index
- `ft_putchar_fd` — write char to fd
- `ft_putstr_fd` — write string to fd
- `ft_putendl_fd` — write string + newline to fd
- `ft_putnbr_fd` — write int to fd

### Part 3 — linked lists

- `ft_lstnew` — new node
- `ft_lstadd_front` — add to front
- `ft_lstsize` — count nodes
- `ft_lstlast` — get last node
- `ft_lstadd_back` — add to back
- `ft_lstdelone` — delete one node
- `ft_lstclear` — delete whole list
- `ft_lstiter` — apply function to each node
- `ft_lstmap` — new list from mapping function
