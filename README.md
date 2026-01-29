### _This project has been created as part of the 42 curriculum by yartym_

## About

**ft_printf** is a project that requires recoding the famous C library function `printf`. The goal is to learn about variadic functions (`stdarg.h`) and structure a program to be extensible and maintainable.

This implementation creates a library `libftprintf.a` that mimics the behavior of the original `printf` for specific conversions and flags.

## Features

### Supported Conversions
| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | The `void *` pointer argument has to be printed in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

### Bonus Flags Supported
This implementation handles the following flags and modifiers:

| Flag | Description |
| :--- | :--- |
| `-` | Left-justify within the given field width; Right justification is the default. |
| `0` | Left-pads the number with zeroes (0) instead of spaces when padding is specified. |
| `.` | **Precision**: Specifies the minimum number of digits to appear for d, i, u, x, X conversions or the maximum number of characters for s conversions. |
| `#` | **Hash**: Used with x or X conversions the value is preceeded with 0x or 0X respectively for values different than zero. |
| ` ` | **Space**: A blank should be left before a positive number (or empty string) produced by a signed conversion. |
| `+` | **Plus**: A sign (+ or -) should always be placed before a number produced by a signed conversion. |
| `width` | Minimum number of characters to be printed. |

## Installation

To compile the library, run:

```bash
make
```

This will generate the libftprintf.a file.

💻 Usage
To use this library in your code, include the header and link the library during compilation.

1. Include the Header

```c
#include "ft_printf.h"
```
2. Compile Your Program

```Bash
cc main.c libftprintf.a -o my_program
```

3. Run
```bash
./my_program
```
