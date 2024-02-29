/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:55:17 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/02/08 13:02:18 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <libc.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_isalpha(int a); // 1 = alphabet
int		ft_isdigit(int a); // 1 = digit
int		ft_isalnum(int a); // 1 = alphabet or digit
int		ft_isascii(int a); // 1 = ascii character
int		ft_isprint(int a); // 1 = it's printable

int		ft_toupper(int a); //to change to capital letter
int		ft_tolower(int a); //to change to miniscules
int		ft_atoi(const char *str); //to change from char to int
char	*ft_itoa(int n); // to change from int to char

/**
 * @brief To count the string size
 * 
 * @param str String
 * @return size_t - len
 */
int	ft_strlen(const char *str);

/**
 * @brief compare 2 string (n characters)
 * 
 * @param str1 
 * @param str2 
 * @param n characters to campare
 * @return int - return the difference between (str1[i] - str2[i])
 */
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * @brief  // copy 'l' characters from src to dst
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t - the size of the string copied
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief concatenate 'l' characters from src to dst
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t - the size of the new str
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief to check if the 'c' character is in the string
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief to check if the 'c' character is in the string
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief  to find 'needle' into 'haystack' and return the find
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* - return the finded
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief to create (duplicate) a string
 * 
 * @param s1 the string to duplicate
 * @return char* - the string created
 */
char	*ft_strdup(const char *s1);

/**
 * @brief create a substring from start, with len size
 * 
 * @param s the main string
 * @param start where start thr substring
 * @param len size of the substring
 * @return char* - the substring
 */
char	*ft_substr(char const *s, int start, int len);

/**
 * @brief Concadenate de s2 into s1, creating a new str
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief create a new str applying the Function to each character to the str
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));

/**
 * @brief apply the Funcion in each character of the str, modifying the str
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief delete characters from the start and the fianl of s1
 * 
 * @param s1 
 * @param set the characters to delete
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief create a str filled with 0s
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * @brief create substring 
 * 
 * @param s 
 * @param c the character to delimitate the string
 * @return char** 
 */
char	**ft_split(char const *s, char c);

/**
 * @brief delete the data of the str, and fill it with zeroes
 * 
 * @param str 
 * @param n 
 */
void	ft_bzero(void *str, size_t n);

/**
 * @brief delete the data of str and fill it with the c character
 * 
 * @param d 
 * @param c the character to fill the str
 * @param len 
 * @return void* 
 */
void	*ft_memset(void *d, int c, size_t len);

/**
 * @brief copy n bytes 
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief copy n bytes
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief compare the first n bytes of the memory areas of the string
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief check if the c character is in the string
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* a pointer of the localitacion
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief write the string in fd
 * 
 * @param str 
 * @param fd where the string will be writed
 */
void	ft_putstr_fd(char *str, int fd);

/**
 * @brief write the character in fd
 * 
 * @param c 
 * @param fd where the string will be writed
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief write the string in fd, followed by a new line
 * 
 * @param s 
 * @param fd where the string will be writed
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief write the number in fd
 * 
 * @param n 
 * @param fd where the string will be writed
 */
void	ft_putnbr_fd(int n, int fd);

/** Printf **/
int		ft_printf(const char *type, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr, int i);
int		ft_putptr(void *ptr);
int		ft_putunbr(unsigned int nbr, int i);
int		ft_puthex(char *base, unsigned int nbr, int i);
int		ft_strlen(const char *str);

/** List Functions **/
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/** Get Next Line **/
char			*get_next_line(int fd);

#endif
