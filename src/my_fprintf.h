/*
** my_fprintf.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 22:14:18 2016 Arthur Melin
** Last update Wed Feb 22 01:10:59 2017 Arthur Melin
*/

#ifndef MY_FPRINTF_H_
# define MY_FPRINTF_H_

# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include "my.h"

typedef struct	s_fprintf_fmt
{
  char		flag_ljust;
  char		flag_plus;
  char		flag_space;
  char		flag_hash;
  char		flag_zero;
  int		field_width;
  int		precision;
  int		length_modifier;
  char		specifier;
}		t_fprintf_fmt;

typedef struct		s_fprintf_nbr_fmt
{
  t_fprintf_fmt 	*fmt;
  char			*base;
  char			*prefix;
}			t_fprintf_nbr_fmt;

typedef int (t_fprintf_func)(int, t_fprintf_fmt *, va_list *, int *);

typedef struct		s_fprintf_func_map
{
  char			chr;
  t_fprintf_func	*func;
}			t_fprintf_func_map;

void	my_fprintf_parse_flags(t_fprintf_fmt *f, const char **s);
void	my_fprintf_parse_width(t_fprintf_fmt *f, const char **s, va_list *a);
void	my_fprintf_parse_prec(t_fprintf_fmt *f, const char **s, va_list *a);
void	my_fprintf_parse_length(t_fprintf_fmt *f, const char **s);

void	my_fprintf_func_map_fill(t_fprintf_func_map *map);

int	my_fprintf_nbr(int fd, t_fprintf_nbr_fmt *fmt,
		       uintmax_t nbr, int *written_ptr);

uintmax_t	my_fprintf_arg_mask(int length_modifier);

t_fprintf_func	my_fprintf_nbr_dec_s;
t_fprintf_func	my_fprintf_nbr_dec_u;
t_fprintf_func	my_fprintf_nbr_oct;
t_fprintf_func	my_fprintf_nbr_bin;
t_fprintf_func	my_fprintf_nbr_hex_l;
t_fprintf_func	my_fprintf_nbr_hex_u;
t_fprintf_func	my_fprintf_chr;
t_fprintf_func	my_fprintf_str;
t_fprintf_func	my_fprintf_str_np;
t_fprintf_func	my_fprintf_ptr;
t_fprintf_func	my_fprintf_wrt;
t_fprintf_func	my_fprintf_pct;
t_fprintf_func	my_fprintf_err;

#endif /* !MY_FPRINTF_H_ */
