<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/libft-light.png?raw=true#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/libft-dark.png?raw=true#gh-dark-mode-only" alt="Banner (oscuro)" />
    <br>
    This project is about coding a C library. It will contain a lot of general purpose functions your programs will rely upon.
    <br>
    <a href='https://profile.intra.42.fr/users/ppinedo-' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/>
    </a>
</div>

---

# Mandatory part

<table>
  <tr>
    <th>Program name</th>
    <td><em>libft.a</em></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>Makefile, <code>libft.h</code>, <code>*.c</code></td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td><em>NAME</em>, <em>all</em>, <em>clean</em>, <em>fclean</em>, <em>re</em></td>
  </tr>
  <tr>
    <th>External functions</th>
    <td>Detailed below</td>
  </tr>
  <tr>
	<th>Libft authorized</th>
	<td>n/a</td>
  </tr>
  <tr>
    <th>Descripción</th>
    <td>Write your own library: a collection of functions
that will be a useful tool for your cursus.
  </tr>
</table>

## Technical considerations

- Declaring global variables is forbidden.
- If you need helper functions to split a more complex function, define them as static
functions. This way, their scope will be limited to the appropriate file.
- Place all your files at the root of your repository.
- Turning in unused files is forbidden.
- Every .c files must compile with the flags ``-Wall -Wextra -Werror``.
- You must use the command ar to create your library. Using the ``libtool`` command
is forbidden.
- Your ``libft.a`` has to be created at the root of your repository.

## Part 1 - Libc functions
You must redo a set of functions from the libc. Your functions will have the
same prototypes and implement the same behaviors as the originals. They must comply
with the way they are defined in their man. The only difference will be their names. They
will begin with the ’``ft_``’ prefix. For instance, ``strlen`` becomes ``ft_strlen``.

You must write your own function implementing the following original ones. They do
not require any external functions:

<table>
  <tr>
    <td><code>isalpha</code></td>
    <td><code>isdigit</code></td>
    <td><code>isalnum</code></td>
  </tr>
  <tr>
    <td><code>isascii</code></td>
    <td><code>isprint</code></td>
    <td><code>strlen</code></td>
  </tr>
  <tr>
    <td><code>memset</code></td>
    <td><code>bzero</code></td>
    <td><code>memcpy</code></td>
  </tr>
  <tr>
    <td><code>memmove</code></td>
    <td><code>strlcpy</code></td>
    <td><code>strlcat</code></td>
  </tr>
  <tr>
    <td><code>toupper</code></td>
    <td><code>tolower</code></td>
    <td><code>strchr</code></td>
  </tr>
  <tr>
    <td><code>strrchr</code></td>
    <td><code>strncmp</code></td>
    <td><code>memchr</code></td>
  </tr>
  <tr>
    <td><code>memcmp</code></td>
    <td><code>strnstr</code></td>
    <td><code>atoi</code></td>
  </tr>
</table>

In order to implement the two following functions, you will use ``malloc()``:
- ``calloc``
- ``strdup``

## Part 2 - Additional functions

In this second part, you must develop a set of functions that are either not in the libc,
or that are part of it but in a different form.

<table>
  <tr>
    <th>Nombre de la función</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td><code>ft_substr()</code></td>
    <td>Allocates and returns a substring</td>
  </tr>
  <tr>
    <td><code>ft_strjoin()</code></td>
    <td>Allocates and returns a new string as a result of concatenation.</td>
  </tr>
  <tr>
    <td><code>ft_strtrim()</code></td>
    <td>Allocates and returns a copy of a string with all specified characters of a 'set' string removed from the beginning and end.</td>
  </tr>
  <tr>
    <td><code>ft_split()</code></td>
    <td>Allocates and returns an array of strings obtained by splitting a string by a delimiter.</td>
  </tr>
  <tr>
    <td><code>ft_itoa()</code></td>
    <td>Allocates and returns a string representing the integer recieved as an arguments. Negative numbers must be handled.</td>
  </tr>
  <tr>
    <td><code>ft_strmapi()</code></td>
    <td>Apply a function to all characters of a string.</td>
  </tr>
  <tr>
    <td><code>ft_striteri()</code></td>
    <td>Apply a function to all characters of a string with the index of a character</td>
  </tr>
  <tr>
    <td><code>ft_putchar_fd()</code></td>
    <td>Outputs a character to the specified file descriptor. </td>
  </tr>
  <tr>
    <td><code>ft_putstr_fd()</code></td>
    <td>Outputs a string to the specified file descriptor.</td>
  </tr>
  <tr>
    <td><code>ft_putendl_fd()</code></td>
    <td>Outputs a string to the specified file descriptor, adding a newline at the end.</td>
  </tr>
  <tr>
    <td><code>ft_putnbr_fd()</code></td>
    <td>Outputs a number to the specified file descriptor.</td>
  </tr>
</table>

# Bonus part

Functions to manipulate memory and strings is very useful. But you will soon discover
that manipulating lists is even more useful. <br>
You have to use the following structure to represent a node of your list. Add its
declaration to your ``libft.h`` file:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```
The members of the t_list struct are:
- content: The data contained in the node.
``void *`` allows to store any kind of data.
- next: The address of the next node, or ``NULL`` if the next node is the last one.
In your Makefile, add a make bonus rule to add the bonus functions to your ``libft``.a.

<table>
  <tr>
    <th>Nombre de la función</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td><code>ft_lstnew()</code></td>
    <td>Creates a new node with the specified content, pointing <code>next</code> to <code>NULL</code>.</td>
  </tr>
  <tr>
    <td><code>ft_lstadd_front()</code></td>
    <td>Adds a new node at the beginning of the list.</td>
  </tr>
  <tr>
    <td><code>ft_lstsize()</code></td>
    <td>Counts the number of nodes in a list.</td>
  </tr>
  <tr>
    <td><code>ft_lstlast()</code></td>
    <td>Returns the last node of the list.</td>
  </tr>
  <tr>
    <td><code>ft_lstadd_back()</code></td>
    <td>Adds the node ’new’ at the end of the list.
</td>
  </tr>
  <tr>
    <td><code>ft_lstdelone()</code></td>
    <td>Removes a node from the list.</td>
  </tr>
  <tr>
    <td><code>ft_lstclear()</code></td>
    <td>Deletes a list.</td>
  </tr>
  <tr>
    <td><code>ft_lstiter()</code></td>
    <td>Iterate through the list and apply a function to each node.</td>
  </tr>
  <tr>
    <td><code>ft_lstmap()</code></td>
    <td>Iterate through the list and apply a function to each node, deleting the progress if failed.</td>
  </tr>
</table>