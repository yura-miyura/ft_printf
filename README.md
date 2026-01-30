#### _This project has been created as part of the 42 curriculum by yartym_


### About

**ft_printf** is a custom implementation of the standard C library function `printf`. This project is part of the 42 curriculum and focuses on learning about variadic functions in C and building an extensible formatting engine.

---

### Algorithm Design

The core algorithm processes the input string character by character, scanning for the `%` delimiter which acts as the trigger for format specifications.

1.  **Parsing:** When a `%` is detected, a dedicated parsing function traverses the subsequent characters to collect **flags**, **field width**, and **precision**. This data is stored in a temporary structure, and the parser stops once it identifies a conversion specifier or an invalid character.
2.  **Conversion:** The populated structure is passed to a conversion function. This function retrieves the corresponding argument from the `va_list` and handles the formatting and output logic based on the collected flags.
3.  **Error Handling:**
    * If a standard error occurs (e.g., write failure), the function returns `-1`.
    * If an unexpected character is encountered during parsing, it is printed literally without modification.

---

### Features

#### Supported Conversions
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

#### Supported Flags (Bonus)
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

### Project Structure

- `ft_printf.c`: Main entry point and variadic argument handling.
- `format.c`: Logic for parsing the format string and flags into a `t_format` struct.
- `print.c`: Core conversion logic for different types (hex, int, uint).
- `put.c`: Output functions for characters, strings, pointers, and numbers.
- `padding.c`: Handles width, zero, and dash padding logic.
- `len.c`: Utility functions for calculating the length of various types.
- `is.c`: Boolean helper functions for flag and type identification.
- `libft/`: A custom library of utility functions used throughout the project.

---

### Installation & Usage

#### Compilation
To compile the library, run:

```bash
make
```

This will create `libftprintf.a` in the root directory.

#### Integration
To use `ft_printf` in your project, include the header and link the library:

1. **Include the function prototype in your C files:**
   ```c
extern int	ft_printf(const char *str, ...);
   ```

2. **Compile your program with the library:**
   ```bash
   cc main.c libftprintf.a -o main
   ```

---

### Resources
* [pirntf man](https://man7.org/linux/man-pages/man3/printf.3.html)
* [variadic functions](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
* [format identifiers](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)
* lots of testing

#### AI have been used only to edit this README
* [GEMINI for README.md](https://gemini.google.com/app/578fb5376022a7bf?is_sa=1&is_sa=1&android-min-version=301356232&ios-min-version=322.0&campaign_id=bkws&utm_source=sem&utm_medium=paid-media&utm_campaign=bkws&pt=9008&mt=8&ct=p-growth-sem-bkws&gclsrc=aw.ds&gad_source=1&gad_campaignid=20108148187&gbraid=0AAAAApk5BhldpHyDLG9wZ_0wVYxGKFEZk&gclid=Cj0KCQiAp-zLBhDkARIsABcYc6tDUIutc7C8iDjQTh62LJes23R0UPQCw3aoPppS2dWEAW7Q1B9103MaAp_REALw_wcB)

