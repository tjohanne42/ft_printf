/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:19:13 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/13 16:19:14 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
#include <locale.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 100
# endif

# ifndef STRUCT_T_RETURN
#  define STRUCT_T_RETURN

typedef unsigned char	t_byte;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strnstr(const char	*big, const char
					*little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
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
t_list				*ft_lstnew(void	const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
char				*ft_strnjoin(const char *s1, const char *s2,
					int s1_len, int s2_len);
size_t				ft_nbrlen(intmax_t nb);
char				*ft_itoa_base(intmax_t nb, size_t base);

typedef	struct	s_return
{
	size_t		buff_size_multi;
	int			ptr_cs;
	int			ptr_bff;
	char		type;
	size_t		len;

	int			sharp;
	int			zero;
	int			negative;
	int			positive;
	int			space;
	int			accuracy;
	int			width;
	int			h;
	int			hh;
	int			ll;
	int			l;
	int			j;
	int			z;
	int			lfloat;
}				t_return;

# endif

int				ft_printf(const char *str, ...);
size_t			take_flag(const char *str, va_list *ap,
				t_return *flag, char **buff);
size_t			take_flag_func(va_list *ap, const char *str,
				t_return *flag, int temp);
size_t			parser(va_list *ap, t_return *flag, char **buff,
				const char *str);

size_t			convert_decimal(va_list *ap, t_return *flag, char **buff);
size_t			decimal_flag_two(char **str, t_return *flag, intmax_t nb,
				char **buff);
size_t			convert_hexadecimal(va_list *ap, t_return *flag, char **buff);
size_t			convert_octal(va_list *ap, t_return *flag, char **buff);
size_t			convert_unsigned(va_list *ap, t_return *flag, char **buff);
size_t			convert_string(va_list *ap, t_return *flag, char **buff);
size_t			convert_wstring(va_list *ap, t_return *flag, char **buff);
size_t			convert_wchar(va_list *ap, t_return *flag, char **buff);
size_t			convert_char(va_list *ap, t_return *flag, char **buff);
size_t			convert_pointer(va_list *ap, t_return *flag, char **buff);
size_t			convert_pourcent(t_return *flag, char **buff);
size_t			convert_unvalid(t_return *flag, char **buff, const char *str);
size_t			convert_float(va_list *ap, t_return *flag, char **buff);

size_t			flag_negative(char **str, t_return *flag);
size_t			flag_width(char **str, t_return *flag);
size_t			flag_zero(char **str, t_return *flag);

void			insert_char(const char c, char **buff, t_return *flag);
void			insert_str(const char *str, char **buff, t_return *flag,
				size_t len);
char			*ft_uitoa_base(uintmax_t nb, size_t base);
char			*wchar_utf8(intmax_t i);
size_t			ft_wstrlen(const wchar_t *str);
char			*ft_ftoa(long double nb, size_t decimals);

#endif
