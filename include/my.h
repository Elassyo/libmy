/*
** my.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Thu Apr  6 18:07:27 2017 Arthur Melin
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** LIBMY
** A very basic my_libc - by arthur.melin@epitech.eu
*/

/*
** Math macros
*/
# define MY_ABS(x)		(x < 0 ? -x : x)
# define MY_MIN(a, b)		(a < b ? a : b)
# define MY_MAX(a, b)		(a > b ? a : b)
# define MY_CLAMP(v, l, h)	(l > v ? l : v < h ? v : h)
# define MY_SQ(x)		(x * x)

# define MY_PI			3.14159265359
# define MY_INF			(1.0 / 0.0)
# define MY_NAN			(0.0 / 0.0)

/*
** Debugging macros
*/
# define MY_STR(v)		#v
# define MY_STRMACRO(m)		MY_STR(m)
# define MY_ASSERT(s)		__FILE__ "(" MY_STRMACRO(__LINE__) "):" s

/*
** Shorthand macros with commonly used parameters
*/
# define my_die(str)		my_die_n(str, 84)
# define my_putc(c)		my_fputc(STDOUT_FILENO, c)
# define my_putnc(c, n)		my_fputnc(STDOUT_FILENO, c, n)
# define my_puts(str)		my_fputs(STDOUT_FILENO, str)
# define my_puterr(err)		my_fputs(STDERR_FILENO, err)
# define my_swap_int(a, b)	my_swap(a, b, sizeof(int))
# define my_swap_char(a, b)	my_swap(a, b, sizeof(char))
# define my_swap_ptr(a, b)	my_swap(a, b, sizeof(void *))
# define my_swap_str(a, b)	my_swap_ptr(a, b)

/*
** Multiline macros as functions (aka norme dodging)
*/
int	my_die_n(const char *s, const int n);
void	*my_die_null(const char *s);
/*
** Formatted and unformatted text output
*/
int	my_printf(const char *fmt, ...);
int	my_fprintf(int fd, const char *fmt, ...);
int	my_vfprintf(int fd, const char *fmt, va_list *va);
void	my_fputc(int fd, int c);
void	my_fputnc(int fd, int c, size_t n);
void	my_fputs(int fd, const char *s);

/*
** Basic IO functions
*/
char	*my_read_line(int fd);
char	*my_read_file(int fd);
char	*my_read_file_bin(int fd, size_t *n);

/*
** Buffered IO functions
*/
typedef struct s_iobuf	t_iobuf;

t_iobuf		*my_iobuf_init(int fd);
void		my_iobuf_free(t_iobuf *iobuf);
void		my_iobuf_flush(t_iobuf *iobuf);
void		my_iobuf_putc(t_iobuf *iobuf, int c);
void		my_iobuf_puts(t_iobuf *iobuf, const char *s);

/*
** Math functions
*/
double	my_pow(double x, unsigned int y);
int	my_sqrt(unsigned int x);

/*
** Number printing parsing
*/
int	my_putnbr(int n);
int	my_atoi(const char *s);
long	my_atol(const char *s);
double	my_atof(const char *s);

/*
** ctype.h functions
*/
int	my_isalnum(int c);
int	my_isalpha(int c);
int	my_isupper(int c);
int	my_islower(int c);
int	my_isdigit(int c);
int	my_isprint(int c);

/*
** ctype.h functions extended for strings
*/
int	my_str_isalpha(const char *s);
int	my_str_isupper(const char *s);
int	my_str_islower(const char *s);
int	my_str_isdigit(const char *s);
int	my_str_isprint(const char *s);

/*
** CPool string manipulation functions
*/
char	*my_revstr(char *s);
char	*my_strupcase(char *s);
char	*my_strlowcase(char *s);
char	*my_strcapitalize(char *s);

/*
** string.h string manipulation functions
*/
size_t	my_strlen(const char *s);
size_t	my_strspn(const char *s1, const char *s2);
size_t	my_strcspn(const char *s1, const char *s2);
int	my_strcmp(const char *s1, const char *s2);
int	my_strcmp_nocase(const char *s1, const char *s2);
int	my_strncmp(const char *s1, const char *s2, size_t n);
char	*my_strcat(char *dest, const char *src);
char	*my_strncat(char *dest, const char *src, size_t n);
char	*my_strcpy(char *dest, const char *src);
char	*my_strncpy(char *dest, const char *src, size_t n);
char	*my_strdup(const char *s);
char	*my_strtok(char *str, const char *delim);
const char	*my_strchr(const char *s, int c);
const char	*my_strrchr(const char *s, int c);
const char	*my_strstr(const char *haystack, const char *needle);

/*
** string.h memory manipulation functions
*/
int	my_memcmp(const void *s1, const void *s2, size_t n);
void	*my_memcpy(void *dest, const void *src, size_t n);
void	*my_memdup(const void *src, size_t n);
void	*my_memset(void *ptr, int c, size_t n);
const void	*my_memchr(const void *ptr, int c, size_t n);
const void	*my_memrchr(const void *ptr, int c, size_t n);

/*
** Allocations
*/
void	*my_realloc(void *src, size_t old, size_t new, size_t element);

/*
** Swap
*/
int	my_swap(void *a, void *b, size_t n);

/*
** Wordtab manipulation functions
*/
char	**my_str_to_wordtab(const char *s);
int	my_wordtab_len(char **tab);
int	my_show_wordtab(char **tab);
void	my_free_wordtab(char **tab);
void	my_sort_int_tab(int *tab, size_t n);

#endif /* !MY_H_ */
