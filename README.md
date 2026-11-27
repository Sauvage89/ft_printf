*This project has been created as part of the 42 curriculum by lensauva.*

--- 
# DESCRIPTION

`ft_printf` is a project from the 42 curriculum.

The goal is to recode the standard C printf() function by implementing a custom formatted output library.

The project focuses on understanding variadic functions in C, managing arguments of different types, parsing format strings, and producing formatted output.

The library implements the following conversions:
- `%c – character`
- `%s – string`
- `%p – pointer address in hexadecimal`
- `%d – signed decimal integer`
- `%i – signed decimal integer`
- `%u – unsigned decimal integer`
- `%x – lowercase hexadecimal`
- `%X – uppercase hexadecimal`
- `%% – literal percent sign`

Constraints followed in this project:
- `Written in C, in accordance with the 42 Norm.`
- `Compiled with cc and the flags -Wall, -Wextra, and -Werror.`
- `Uses variadic arguments through stdarg.h.`
- `No buffer management from the original printf().`
- `The library is created using ar.`
- `No unexpected crashes or memory errors.`

---
# INSTRUCTION

## Compilation

At the root of the repository:
- `make`        # builds libftprintf.a
- `make clean`  # removes object files
- `make fclean` # removes object files and libftprintf.a
- `make re`     # fclean + all

The Makefile provides the rules all, clean, fclean and re, and avoids unnecessary relinking.

## Dependencies

This project uses libft as a Git submodule.

To clone the project with its dependencies:
- `git clone --recurse-submodules <repository_url>`

if the repository has already been cloned without its submodules:
- `git submodule update --init --recursive`

## Usage

Include the header in your source file:
- `#include "ft_printf.h"`

Compile your program and link it against the library:
- `cc main.c -L<directory where are the file libftprintf.a> -lftprintf -o my_program`

---
# RESOURCES

## References
- `printf(3) – Linux manual page`
- `The 42 Norm`
- `Peer-to-peer learning`
- `Inthernet`

## COMPORTEMENT OF FLAG

### flag <->

| `type value` | purpose |
|--------------|---------|
| | overwritten by flag <.> |
| | overwritten by flag <0> |
| | the sign counts for len(value) |
| | the space of flag < > counts for len(value) |
| | the plus of flag <+> counts for len(value) |
| | the '0x' of flag <#> counts for len(value) |
| | the '0x' of %p counts for len(value) |
| c s d i u x X p | if the number of the flag is greater than len(value), add ' ' for the difference. |
| | if the number of the flag is lower than len(value), don't take care of the purpose of the flag. |


### flag <0>

| `type value` | purpose |
|--------------|---------|
| | overwritten by flag <-> |
| | overwritten by flag <.> |
| | the sign counts for len(value) |
| | the space of flag < > counts for len(value) |
| | the plus of flag <+> counts for len(value) |
| | the '0x' of flag <#> counts for len(value) |
| | the '0x' of flag <p> counts for len(value) |
| d i u x X | if the number of the flag is greater than len(value), add '0' for the difference. |
| | if the number of the flag is lower than len(value), don't take care of the purpose of the flag. |
| p | if the number of the flag is greater than len(value), add '0' after '0x' for the difference. |
| | if the number of the flag is lower than len(value), don't take care of the purpose of the flag. |
| c s | do nothing |


### flag <.>

| `type value` | purpose |
|--------------|---------|
| | overwrites the flag <0> |
| | overwrites the flag <-> |
| | the sign doesn't count for len(value) |
| | the space of flag < > doesn't count for len(value) |
| | the plus of flag <+> doesn't count for len(value) |
| | the '0x' of flag <#> doesn't count for len(value) |
| | the '0x' of %p doesn't count for len(value) |
| d i u x X p | if the number of the flag is greater than len(value), add '0' for the difference. |
| | if the number of the flag is lower than len(value), don't take care of the purpose of the flag. |
| s | print the maximum number of characters specified after <.> from the string |
| c | do nothing |


### flag <#>

| `type value` | purpose |
|--------------|---------|
| | if value is 0, don't print '0x' |
| c s d i u p | do nothing |
| x | add '0x' at the beginning of value |
| X | add '0X' at the beginning of value |


### flag < >

| `type value` | purpose |
|--------------|---------|
| | overwritten by flag <+> |
| c s u x X | do nothing |
| p i d | if value is positive, add a space before the value |


### flag <+>

| `type value` | purpose |
|--------------|---------|
| | overwrites the flag < > |
| c s u x X | do nothing |
| p i d | if value is positive, add a plus before the value |


### flag <width>

In the research the comportement of width was nor researched and its result on the abandon of bonus part for this project

## Use of AI

- Documentation and research related to C syntax, variadic arguments, and printf() behavior.
- Assistance with Makefile structure and compilation rules.
- README writing and proofreading.
