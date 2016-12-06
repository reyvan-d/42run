/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:33:30 by khansman          #+#    #+#             */
/*   Updated: 2016/11/12 18:05:49 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** ----------\
** Includes   |
** ----------/
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** get_next_line
*/
# define BUFF_SIZE 32
# define NUM_BUFF  10
# define LINE_SIZE 50

# define ACTIVE    buff->active
# define POS       buff->pos
# define AB_POS    (buff->pos % BUFF_SIZE)
# define BUFF      buff->buff
# define B_FD      buff->fd
# define RET       buff->ret
# define L         buff->l
# define LINE      buff->line

# define BUFF_END (BUFF[POS] == '\0' && RET < BUFF_SIZE)

/*
** base strings
*/

# define BASE_STR static char *b = "0123456789ABCDEF";
# define BASE_STR2 char *base = "0123456789abcdef";

# define SKP_BLK while (*tmp == c) ++tmp;

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_buff
{
	char			buff[BUFF_SIZE];
	char			active;
	int				fd;
	int				ret;
	int				pos;
	int				l;
	char			*line;
}					t_buff;

typedef struct		s_base_var
{
	long int		num;
	long int		l;
	unsigned int	k;
	long int		ba;
	char			*str;
}					t_base_var;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ----------\
** Prototypes |
** ----------/
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_list);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					get_next_line(const int fd, char **line);
void				ft_free2d(char **arr);
char				*ft_remalloc(char *line, size_t size);
int					ft_get_line(int fd, char **line);
char				*ft_itoa_base(int value, int base);
void				ft_print_hex(unsigned char num);
void				ft_print_memory(const void *addr, size_t size);
void				ft_die(char *str);
char				*ft_strtolower(char *str);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
