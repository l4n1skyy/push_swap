*This project has been created as part of the 42 curriculum by lanusri-.*

# ft_printf

## Description

- `ft_printf` is a recreation of the C standard library's `printf` function.
- Goal: reimplement formatted output from scratch, without using the original `printf`.
- Supports the following conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
- Built as a static library (`libftprintf.a`) so it can be linked into other C projects.

## Instructions

- Compile the library with:
  `make`
  `make clean`      — remove object files
  `make fclean`     — remove object files and the library
  `make re`         — rebuild from scratch

## Algorithm and Data Structure

- ft_ctoa writes one character; every other conversion builds on it.
- ft_stoa/ft_utoa/ft_itoa convert strings/unsigned/signed integers, with ft_itoa special-casing INT_MIN.
- ft_xtoa/ft_bigxtoa build hex digits into a heap buffer for lowercase/uppercase output; ft_ptoa reuses this with a 0x prefix.
- ft_printf walks the format string, printing literals directly and dispatching % conversions via ft_eval_format.
- Each function returns its character count, summed into ft_printf's return value.

## Resources

- Youtube https://youtu.be/byRw36Y3Hjs?si=d3OsbLOXtQcS0Txs, video to understand va functions
- AI was used for reviewing the code for logical bugs and edge cases, also helped me to paraphrase my README so it sounds nicer
