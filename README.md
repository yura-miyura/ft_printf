# ft_printf

![42 Badge](https://img.shields.io/badge/42-%20London-black?style=flat-square&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)

**ft_printf** is a custom implementation of the standard C library function `printf`. This project is part of the 42 curriculum and focuses on learning about variadic functions in C and building an extensible formatting engine.

## 🚀 Features

### Supported Conversions
| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a `void *` pointer argument in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

### Supported Flags (Bonus)
This implementation handles the following flags and modifiers:

| Flag | Description |
| :---: | :--- |
| `-` | Left-justify within the given field width. |
| `0` | Left-pads the number with zeroes (0) instead of spaces. |
| `.` | **Precision**: Specifies min digits for numbers or max chars for strings. |
| `#` | **Hash**: Adds `0x` or `0X` prefix for `x` or `X` conversions. |
| ` ` | **Space**: Leaves a blank before a positive number. |
| `+` | **Plus**: Always places a sign (+ or -) before a number. |
| `width` | Specifies the minimum number of characters to be printed. |

---

## 🛠️ Project Structure

- `ft_printf.c`: Main entry point and variadic argument handling.
- `format.c`: Logic for parsing the format string and flags into a `t_format` struct.
- `print.c`: Core conversion logic for different types (hex, int, uint).
- `put.c`: Output functions for characters, strings, pointers, and numbers.
- `padding.c`: Handles width, zero, and dash padding logic.
- `len.c`: Utility functions for calculating the length of various types.
- `is.c`: Boolean helper functions for flag and type identification.
- `libft/`: A custom library of utility functions used throughout the project.

---

## 📦 Installation & Usage

### Compilation
To compile the library, run:

```bash
make
```

This will create `libftprintf.a` in the root directory.

### Integration
To use `ft_printf` in your project, include the header and link the library:

1. **Include the header in your C files:**
   ```c
   #include "ft_printf.h"
   ```

2. **Compile your program with the library:**
   ```bash
   cc main.c libftprintf.a -o main
   ```

---

## 🧪 Testing
You can create a `main.c` file and test various cases:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Hex: %#x\n", 42);
    ft_printf("Width and Precision: %10.5d\n", 42);
    return (0);
}
```

---

## 👤 Author
- **yartym** (yartym@student.42london.com)