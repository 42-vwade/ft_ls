/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:34:03 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 15:00:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "libft_include.h"
# include "libft_macros.h"
# include "libft_structs.h"

/*
**		STANDARD OUTPUT
*/

int32_t		ft_printf(const char *format, ...);
int32_t		ft_vprintf(const char *format, va_list ap);
void		ft_putchar(int32_t c);
void		ft_putchar_fd(char c, int32_t fd);
void		ft_putwchar(uint32_t wc);
size_t		write_utf8(uint32_t wc);
size_t		write_utf8_fd(uint32_t wc, int32_t fd);
size_t		print_utf8(uint32_t *int32_str);
size_t		print_utf8_n(uint32_t *int32_str, size_t length);
caddr_t		encode_utf8(int32_t *wc);
caddr_t		encode_utf8_w(int32_t *l_str, size_t bytes_allowed);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int32_t fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int32_t fd);
void		ft_putnbr(int64_t number);
void		ft_putnbr_fd(int64_t number, int32_t file_descriptor);
void		ft_putnbr_u(uint32_t number);
void		print_float(float n, size_t precision);
void		print_double(double_t value, uint32_t precision);
caddr_t		infinite_double(double_t value, uint64_t precision);
size_t		write_infinite_double(double_t value, uint64_t precision);

/*
**	I am probably categorizing the ft_strtoi and ft_strtol very incorrectly.
**	The intention is to convert an array of chars into an array of ints/longs.
**	The functions do that. The names may be inappropriate.
*/

int32_t		*ft_strtoi(char *str);
int64_t		*ft_strtol(char *str);
int32_t		*str_utf8(wchar_t *l_str);
int64_t		ft_power(long long int_base, uint32_t int_power);

/*
**		MEMORY SET
*/

void		ft_free(void *ap);
void		*ft_memset(void *b, int32_t c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int32_t c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, uint32_t c, size_t n);
char		ft_cmp(size_t a, size_t b);
uint32_t	ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int32_t c);
char		*ft_strrchr(const char *s, int32_t c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int32_t		ft_strcmp(const char *s1, const char *s2);
int32_t		ft_strncmp(const char *s1, const char *s2, size_t n);
char		*splice_str(char *source, char *fragment, size_t ndx);
char		*search_and_splice(char *source, char *needle, char *fragment);
char		*ft_strcapitalize(char *s);
int32_t		ft_isalpha(int32_t c);
int32_t		ft_isdigit(int32_t c);
int32_t		ft_isalnum(int32_t c);
int32_t		ft_isascii(int32_t c);
int32_t		ft_isprint(int32_t c);
int32_t		ft_isuppercase(char c);
int32_t		ft_toupper(uint32_t c);
int32_t		ft_tolower(uint32_t c);
void		ft_strtoupper(char **str);
void		ft_strtolower(char **str);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);

char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(uint32_t, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(uint32_t, char));
int32_t		ft_strequ(char const *s1, char const *s2);
int32_t		ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, size_t start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
t_str		*tstr_new(char *s);
t_str		*tstr_dup(char *s);
t_str		*tstr_dup_free(char *s);
void		tstr_free(t_str *s);

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void		ft_lstadd(t_list **alst, t_list *newnode);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void		print_bits(uint32_t octal);
void		print_64bits(uint64_t octal);
void		print_64bits_recursive(uint64_t octal);
void		print_hex(uint64_t c);
void		print_memory(const void *addr, size_t size);
uint8_t		swap_bits(uint8_t octet);
uint8_t		reverse_bits(uint8_t octet);
void		ft_swap(char *a, char *b);
void		ft_memswap(const void *a, const void *b);

uint32_t	ft_astrcmp(char **s1, char **s2);
void		ft_del(void *ap, size_t len);
void		ft_lstpush(t_list **list, t_list *new);
void		ft_lstpop(t_list **list);
void		**ft_lst2arr(t_list *lst);
void		ft_error(const char *message);
char		*ft_append(const char *s1, const char *s2, int32_t mode);
char		*ft_strjoin_free(char const *s1, char const *s2);

/*
**	Utility
*/

long		ft_abs(long n);
long		ft_min(int64_t a, int64_t b);
long		ft_max(int64_t a, int64_t b);
long		ft_square(int64_t n);
double_t	ft_pythagorean_theorem(int64_t a, int64_t b, int64_t c);
double_t	ft_vector_length(t_v3d vector);
char		ft_any2(long match, long criterion_a, long criterion_b);

/*
**	Write to Standard Output
*/

/*
**	FILE I/O
*/

uint32_t	get_next_line(const uint32_t fd, char **line);

/*
**	Length Getters
*/

size_t		ft_strlen(const char *s);
int64_t		ft_wstrlen(wchar_t *s);
size_t		ft_lstrlen(const wchar_t *s);
size_t		ft_intlen(uint64_t value);
int64_t		ft_intlen_base(uint64_t value, int32_t base);
int64_t		ft_lstlen(t_list *lst);
int64_t		ft_arrlen(char **ar);

/*
**	String Modifiers
*/

caddr_t		ft_basename(char *path);

/*
**	Conversion
*/

uint32_t	ft_atoi(const char *str);
u_int64_t	ft_hextol(char *s);
uint64_t	ft_octtol(char *s);
caddr_t		ft_itoa(int64_t value);
caddr_t		ft_itoa_unsigned(uint64_t value);
caddr_t		ft_itoa_base(uint64_t value, uint32_t base);

/*
**	Length Getters
*/

uint32_t	ft_iswhitespace(uint32_t c);
size_t		len_interval(void const *s, size_t interval);
size_t		slen(const char *s, size_t maxsize);

/*
**	Math
*/

double_t	ft_sqrt(long double n);
double_t	ft_sqroot(long double n);

/*
**	Queue
*/

t_queue		*ft_queue(void);
void		ft_enqueue(t_queue *queue, void *content);
void		*ft_dequeue(t_queue *queue);
void		*ft_queue_peek(t_queue *queue);
void		ft_queue_del(t_queue *queue);

/*
**	Stack
*/

t_stack		*ft_stack(void);
void		ft_stack_push(t_stack *stack, void *content);
void		*ft_stack_pop(t_stack *stack);
void		*ft_stack_peek(t_stack *stack);
void		ft_stack_del(t_stack *stack);

/*
**	Length Getters
*/

/*
**	Length Getters
*/

#endif
