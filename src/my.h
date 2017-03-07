/*
** my.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Tue Mar  7 11:04:12 2017 Arthur Melin
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <unistd.h>

/*
** LIBMY
** A very basic my_libc - by arthur.melin@epitech.eu
*/

/*
** Math macros
*/
# define MY_ABS(x) (x < 0 ? -x : x)
# define MY_MIN(a, b) (a < b ? a : b)
# define MY_MAX(a, b) (a > b ? a : b)
# define MY_CLAMP(v, l, h) (l > v ? l : v < h ? v : h)

/*
** Debugging macros
*/
# define MY_STR(v) #v
# define MY_STR_MACRO(m) MY_STR(m)
# define MY_ASSERT(str) __FILE__ ":" MY_STR_MACRO(__LINE__) ": " str

/*
** Shorthand macros with commonly used parameters
*/
# define my_die(err) my_die_n(err, 84)
# define my_putchar(c) my_putchar_fd(STDOUT_FILENO, c)
# define my_putnchar(c, n) my_putnchar_fd(STDOUT_FILENO, c, n)
# define my_putstr(str) my_putstr_fd(STDOUT_FILENO, str)
# define my_puterr(str) my_putstr_fd(STDERR_FILENO, str)

/*
** Multiline macros as functions (aka norme dodging)
*/
int	my_die_n(char *err_msg, int n);
void	*my_die_null(char *err_msg);

/*
** Formatted and unformatted text output
*/
int	my_printf(const char *format, ...);
int	my_fprintf(int fd, const char *format, ...);
int	my_vfprintf(int fd, const char *format, va_list *va);
void	my_putchar_fd(int fd, char c);
void	my_putnchar_fd(int fd, char c, int n);
void	my_putstr_fd(int fd, char *str);

/*
** Basic IO functions
*/
char	*my_read_file(int fd);
char	*my_read_file_bin(int fd, int *size);
char	*my_read_line(int fd);

/*
** Buffered IO functions
*/
typedef struct s_iobuf	t_iobuf;
t_iobuf		*my_iobuf_init(int fd);
void		my_iobuf_free(t_iobuf *iobuf);
void		my_iobuf_flush(t_iobuf *iobuf);
void		my_iobuf_putchar(t_iobuf *iobuf, char c);
void		my_iobuf_putstr(t_iobuf *iobuf, char *str);

/*
** Math functions
*/
long	my_power_ite(int nbr, int power);
int	my_power_rec(int nbr, int power);
int	my_square_root(int nbr);
int	my_isneg(int nbr);
int	my_is_prime(int nbr);
int	my_find_prime_sup(int nbr);

/*
** Number printing and parsing
*/
int	my_putnbr(int nbr);
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr(char *str);
int	my_getnbr_base(char *str, char *base);

/*
** ctype.h functions
*/
int	my_isalnum(char c);
int	my_isalpha(char c);
int	my_isupper(char c);
int	my_islower(char c);
int	my_isnum(char c);
int	my_issign(char c);
int	my_isprint(char c);

/*
** ctype.h functions extended for strings
*/
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);

/*
** string.h string manipulation functions
*/
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp_uncase(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int n);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strdup(char *src);
char	*my_strchr(char *str, char to_find);
char	*my_strstr(char *str, char *to_find);

/*
** CPool string manipulation functions
** TODO: add missing my_strdowncase
*/
char	*my_revstr(char *str);
char	*my_strupcase(char *str);
char	*my_strcapitalize(char *str);

/*
** string.h memory manipulation functions
*/
int	my_memcmp(void *s1, void *s2, int n);
void	*my_memcpy(void *dest, void *src, int size);
void	*my_memset(void *ptr, int c, int size);
void	*my_realloc(void *old_buf, int old_sz, int new_sz, int elm_sz);

/*
** Swap functions
** TODO: create multi-purpose version and replace those with shorthand macros
*/
int	my_swap(int *a, int *b);
int	my_swap_char(char *a, char *b);
int	my_swap_str(char **a, char **b);

/*
** Wordtab manipulation functions
*/
char	**my_str_to_wordtab(char *str);
int	my_wordtab_len(char **tab);
int	my_show_wordtab(char **tab);
void	my_free_wordtab(char **tab);
void	my_sort_int_tab(int *arr, int size);

#endif /* !MY_H_ */
