/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:38:35 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:54 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLUE		CYAN
# define RESET		"\x1b[0m"

# define ABS(a) (((a) < 0) ? -(a) : (a))

# define BUFF_SIZE 4

typedef struct	s_field
{
	int		flags[6];
	size_t	width;
	size_t	precision;
	int		size;
	int		type;
	int		is_null;
	char	*arr;
	size_t	buff_size;
	char	c;
}				t_field;

typedef struct	s_type
{
	size_t			unsign;
	ssize_t			sign;
	char			t_char;
	char			*t_str;
	long double		t_ldouble;
	void			*t_void;
}				t_type;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;


typedef struct	s_mlist
{
	char			*content;
	int				fd;
	struct s_mlist	*next;
}				t_mlist;

/*
** ft_is
*/

int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

/*
** ft_str
*/

int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strcheck(char *s, int (*f)(int));
char			*ft_strrev(char *s);
char			*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char			*ft_strcpy(char *destptr, const char *srcptr);
char			*ft_strcat(char *destptr, const char *srcptr);
char			*ft_strncat(char *destptr, char *srcptr, size_t num);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strrchr(const char *string, int symbol);
char			*ft_strdup(const char *str);
char			*ft_strduplen(const char *src, unsigned int len);
char			*ft_strstr(const char *string1, const char *string2);
char			*ft_strnstr(const char *s1, const char *s2, size_t length);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strskip(char const *s, char c);
char			*ft_strndup(const char *str, int len);
char			**ft_strsplit(char const *s, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *string);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/*
** ft_mem
*/

int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void			*ft_memccpy(void *d, const void *s, int ch, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t num);
void			*ft_memchr(const void *ptr, int c, size_t num);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *memptr, int val, size_t num);

/*
** ft_put
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			put_symbol(ssize_t num, char c, t_field *field);
void			ft_putlonglong(ssize_t n, t_field *f);
void			ft_putulonglong(size_t n, t_field *f);
void			ft_putdouble(long double n, t_field *f);

/*
** ft_lst
*/

int				ft_lstsize(t_list *alst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstrev(t_list **alst);
void			ft_lstpush(t_list **h, t_list **t, t_list *new);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*lstfree(t_list **list);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_list_find(t_list *alst, void const *content);

/*
** print
*/

int				ft_printf(const char *format, ...);
void			print_flag_minus(t_type *value_type, t_field *field);
void			print_sign(t_type *v_t, t_field *f);
void			print_precision(t_type *value_type, t_field *field);
void			print_structure(va_list args, t_field *field);
void			print_value(t_type *value_type, t_field *field);

/*
** get
*/

int				get_next_line(const int fd, char **line);
void			get_value_unsign(va_list args, t_type *v, t_field *f);
void			get_value_sign(va_list args, t_type *v, t_field *f);
void			get_value(va_list args, t_type *v, t_field *f);
void			get(va_list args, t_type *v, t_field *f);

/*
** ft
*/

int				ft_nbwords(char *s, char c);
int				ft_flags(const char *format, t_field *field);
long long int	ft_atoi(const char *string);
int				ft_width_precision(const char *form, va_list a, t_field *f);
int				ft_size(const char *format, t_field *field);
void			ft_type(char c, t_field *field);
void			ft_bzero(void *s, size_t n);
void			ft_intswap(int *n1, int *n2);
char			*ft_itoa(int n);
char			*ft_swap(char *s1, int c1, int c2);
char			*ft_octa(size_t n, t_field *field);
char			*ft_hex(size_t n, t_field *field);
char			*ft_itoa_base(__int128 n, int base, char *tab);
size_t			ft_llintlen(ssize_t nb);
size_t			ft_ullintlen(size_t nb);
size_t			ft_intlen(ssize_t nb);


/*
** other
*/

int				fill_structure(const char *form, va_list args, t_field *f);
int				detection(char c);
void			clear_field(t_field *field);
void			clear_type(t_type *type);
void			increase_arr(size_t len, t_field *field);
void			check_arr(t_field *field);
void			str_in_arr(char *s, t_field *field);
ssize_t			diff_width(t_field *field, t_type *value_type);

#endif
