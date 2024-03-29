# Get-Next-Line :bookmark_tabs:

**ft_printf ([42cursus](https://www.42.fr)) 2023**

**Actual Status :** Finished 

**Result :** 125%

This project is dedicated to a convenient feature in [Left.a](https://github.com/AGolz/Libft_42Yerevan) collection, it helps to learn a very interesting thing in C programming: static variables.

## The main part:

<table>
  <tbody>
    <tr>
      <td> Function name  </td>
      <td> get_next_line </td>
    </tr>
    <tr>
      <td> Prototype  </td>
      <td> char *get_next_line(int fd); </td>
    </tr>
	<tr>
      <td> Turn in files </td>
      <td> get_next_line.c, get_next_line_utils.c, get_next_line.h </td>
    </tr>
	<tr>
      <td> Parameters </td>
      <td> fd: The file descriptor to read from </td>
    </tr>
	<tr>
      <td> Return value </td>
      <td> Read line: correct behavior; NULL: there is nothing else to read, or an error occurred</td>
    </tr>
	<tr>
      <td> External functs </td>
      <td> read, malloc, free </td>
    </tr>
	<tr>
      <td> Description </td>
      <td> Write a function that returns a line read from a file descriptor </td>
    </tr>
  </tbody>
</table>

 - Repeated calls (for example, using a loop) to `get_next_line()` should allow reading the text file pointed to by the file descriptor, one line at a time.
 - The function should return the string that was read. If there is nothing else to read or an error has occurred, it should return NULL.
 - The function should work properly both when reading a file and when reading from standard input.
 - The returned string must contain the terminating character `\n`, except when the end of the file has been reached and does not end with the character `\n`.
 - The header file get_next_line.h must contain at least a prototype of the function `get_next_line()`
 - All necessary auxiliary functions must be in the `get_next_line_utils.c` file.

When compiling, add this option to your compiler's call: `-D BUFFER_SIZE=n`.It will determine the buffer size for `read()`.
The buffer size value can be changed for code testing.
```
This project should compile with and without the -D flag
```

#### You can compile the code as follows (buffer size 42 is used as an example):
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
 - `get_next_line()` has undefined behavior if the file specified by the file descriptor has changed since the last call, whereas `read()` has not reached the end of the file.
 - The `get_next_line()` function has undefined behavior when reading a binary file.

#### Forbidden
- It is not allowed to use your `libft` in this project.
- `lseek()` is forbidden.
- Global variables are prohibited.

## Bonus part:

Here are the requirements for the bonus part:
 - Only one static variable should be used in `get_next_line()`.
 - `get_next_line()` must manage multiple file descriptors at the same time.

In addition to the required details file, the following files must be passed
• get_next_line_bonus.c
• get_next_line_bonus.h
• get_next_line_utils_bonus.c

## Running tests

### The main part:

```
cc -Wall -Wextra -Werror get_next_line.h get_next_line.c get_next_line_utils.c main.c 
```
./a.out [file name] [buffer size] 

Example:
```
./a.out test_1 32 test_2 64 test_3 128
```
 ## The bonus part:

```
cc -Wall -Wextra -Werror get_next_line_bonus.h main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out
```
You can add or change the buffer size in the `main_bonus.c` file.

**[Project instructions](https://github.com/AGolz/Get-Next-Line/files/10813008/en.subject.1.pdf)**

Need help: elmaksim@student.42yerevan.am

Special thanks: [tripouille](https://github.com/Tripouille) for the [gnlTester](https://github.com/Tripouille/gnlTester) (:
