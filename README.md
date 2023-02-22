# Get-Next-Line :bookmark_tabs:

**ft_printf ([42cursus](https://www.42.fr)) 2023**

**Actual Status :** Finished 

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
