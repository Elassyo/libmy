/*
** my.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Apr 17 18:30:24 2017 Arthur Melin
*/

/*
** LIBMY by arthur.melin@epitech.eu
**
** Partial implementation of ANSI C and more using only the following syscalls:
**    - malloc
**    - free
**    - read
**    - write
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>

/*
** assert.h: debug macros (doesn't work like assert())
*/
# define MY_STR(v)		#v
# define MY_STRMACRO(m)		MY_STR(m)
# define MY_ASSERT(s)		__FILE__ "(" MY_STRMACRO(__LINE__) "):" s

/*
** ctype.h: character handling functions + extensions to string
*/
int	my_isalnum(int c);
int	my_isalpha(int c);
int	my_isblank(int c);
int	my_iscntrl(int c);
int	my_isdigit(int c);
int	my_isgraph(int c);
int	my_islower(int c);
int	my_isprint(int c);
int	my_ispunct(int c);
int	my_isspace(int c);
int	my_isupper(int c);
int	my_isxdigit(int c);
int	my_str_isalpha(const char *s);
int	my_str_isupper(const char *s);
int	my_str_islower(const char *s);
int	my_str_isdigit(const char *s);
int	my_str_isprint(const char *s);

int	my_tolower(int c);
int	my_toupper(int c);
char	*my_strtolower(char *s);
char	*my_strtoupper(char *s);
char	*my_strcapitalize(char *s);

/*
** math.h: math definitions, macros and power function with some dirty hacks
** to get a non-signaling NaN float
*/
typedef union		u_bin2float
{
  int			b;
  float			f;
}			t_bin2float;

static t_bin2float __attribute__ ((unused))	__my_infinity = { 0x7f800000 };
static t_bin2float __attribute__ ((unused))	__my_nan = { 0x7fffffff };

# define MY_INFINITY		__my_infinity.f
# define MY_NAN			__my_nan.f
# define MY_PI			3.14159265359

# define my_abs(x)		(x < 0 ? -x : x)
# define my_min(a, b)		(a < b ? a : b)
# define my_max(a, b)		(a > b ? a : b)
# define my_clamp(v, l, h)	(l > v ? l : v < h ? v : h)
# define my_sq(x)		(x * x)

double				my_pow(double x, int y);

/*
** stdio.h: some IO functions (putting, formatting and buffered)
*/
# define my_putc(c)	my_fputc(STDOUT_FILENO, c)
# define my_putnc(c)	my_fputnc(STDOUT_FILENO, c)
# define my_puts(s)	my_fputs(STDOUT_FILENO, s)
# define my_puterr(s)	my_fputs(STDERR_FILENO, s)

int			my_printf(const char *fmt, ...);
int			my_fprintf(int fd, const char *fmt, ...);
int			my_vfprintf(int fd, const char *fmt, va_list *va);
void			my_fputc(int fd, int c);
void			my_fputnc(int fd, int c, size_t n);
void			my_fputs(int fd, const char *s);

char			*my_read_line(int fd);
char			*my_read_file(int fd);
char			*my_read_file_bin(int fd, size_t *n);

typedef struct s_iobuf	t_iobuf;

t_iobuf			*my_iobuf_init(int fd);
void			my_iobuf_free(t_iobuf *iobuf);
void			my_iobuf_flush(t_iobuf *iobuf);
void			my_iobuf_putc(t_iobuf *iobuf, int c);
void			my_iobuf_puts(t_iobuf *iobuf, const char *s);

/*
** stdlib.h: string conversion, random number generator and array reallocator
*/
# define MY_EXIT_SUCCESS	0
# define MY_EXIT_FAILURE	84
# define MY_RAND_MAX		18446744073709551615

int		my_atoi(const char *s);
long		my_atol(const char *s);
double		my_atof(const char *s);
long		my_strtol(const char *s, char **endptr, int base);
double		my_strtod(const char *s, char **endptr);

unsigned long	my_rand();
void		my_srand(unsigned long seed);

void		*my_realloc(void *src, size_t old, size_t _new, size_t elem);

/*
** string.h: strings and memory handling
*/
void		*my_memcpy(void *dest, const void *src, size_t n);
void		*my_memmove(void *dest, const void *src, size_t n);
char		*my_strcpy(char *dest, const char *src);
char		*my_strncpy(char *dest, const char *src, size_t n);

char		*my_strcat(char *dest, const char *src);
char		*my_strncat(char *dest, const char *src, size_t n);

int		my_memcmp(const void *s1, const void *s2, size_t n);
int		my_strcmp(const char *s1, const char *s2);
int		my_strcmp_nocase(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, size_t n);
int		my_strncmp_nocase(const char *s1, const char *s2, size_t n);

void		*my_memdup(const void *src, size_t n);
char		*my_strdup(const char *s);

const void	*my_memchr(const void *ptr, int c, size_t n);
const void	*my_memrchr(const void *ptr, int c, size_t n);
const char	*my_strchr(const char *s, int c);
const char	*my_strrchr(const char *s, int c);
const char	*my_strstr(const char *haystack, const char *needle);
size_t		my_strspn(const char *s1, const char *s2);
size_t		my_strcspn(const char *s1, const char *s2);
char		*my_strtok(char *str, const char *delim);

char		*my_strrev(char *s);

void		*my_memset(void *ptr, int c, size_t n);
size_t		my_strlen(const char *s);

/*
** Die macro-like functions to use in returns
*/

int			my_die(const char *fmt, ...);
int			my_die_n(int n, const char *fmt, ...);
void			*my_die_null(const char *fmt, ...);

/*
** Swapping functions
*/
# define my_swap_int(a, b)	my_swap(a, b, sizeof(int))
# define my_swap_char(a, b)	my_swap(a, b, sizeof(char))
# define my_swap_ptr(a, b)	my_swap(a, b, sizeof(void *))
# define my_swap_str(a, b)	my_swap_ptr(a, b)

int				my_swap(void *a, void *b, size_t n);

/*
** Wordtab manipulation functions
*/
char	**my_str_to_wordtab(const char *s);
int	my_wordtab_len(char **tab);
int	my_show_wordtab(char **tab);
void	my_free_wordtab(char **tab);
void	my_sort_int_tab(int *tab, size_t n);

#endif /* !MY_H_ */
