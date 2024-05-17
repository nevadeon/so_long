/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:24:54 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/17 10:42:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_H
# define LIBNDAV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

# define DEC "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

char	*get_next_line(int fd);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dest, const char *src);
void	ft_strcat(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t d_size);
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);

size_t	ft_strclen(const char *str, char c, bool include_char);
char	*ft_strcdup(const char *str, char c, bool include_char);
void	ft_strccat(char *dest, const char *src, char c, bool include_char);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, int n);
void	*ft_memset(void *s, int c, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_printf(int fd, const char *format, ...);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(const char *s, int fd);
size_t	ft_putptr_fd(void *p, int fd);
size_t	ft_putlbase_fd(long n, char *base, int fd);
size_t	ft_putulbase_fd(size_t n, char *base, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif