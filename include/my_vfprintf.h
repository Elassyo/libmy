/*
** my_vfprintf.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 22:14:18 2016 Arthur Melin
** Last update Thu Apr 20 09:24:44 2017 Arthur Melin
*/

#ifndef MY_VFPRINTF_H_
# define MY_VFPRINTF_H_

# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include <my.h>

typedef struct	s_vfprintf_fmt
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
}		t_vfprintf_fmt;

typedef struct		s_vfprintf_nbr_fmt
{
  t_vfprintf_fmt	*fmt;
  char			*base;
  char			*prefix;
}			t_vfprintf_nbr_fmt;

typedef int	t_vfprintf_func(int, t_vfprintf_fmt *, va_list *, int *);

typedef struct		s_vfprintf_func_map
{
  char			chr;
  t_vfprintf_func	*func;
}			t_vfprintf_func_map;

void	my_vfprintf_parse_flags(t_vfprintf_fmt *f, const char **s);
void	my_vfprintf_parse_width(t_vfprintf_fmt *f, const char **s, va_list *a);
void	my_vfprintf_parse_prec(t_vfprintf_fmt *f, const char **s, va_list *a);
void	my_vfprintf_parse_length(t_vfprintf_fmt *f, const char **s);

void	my_vfprintf_func_map_fill(t_vfprintf_func_map *map);

int	my_vfprintf_nbr(int fd, t_vfprintf_nbr_fmt *fmt,
			uintmax_t nbr, int *written_ptr);

uintmax_t	my_vfprintf_arg_mask(size_t length_modifier);

t_vfprintf_func		my_vfprintf_nbr_dec_s;
t_vfprintf_func		my_vfprintf_nbr_dec_u;
t_vfprintf_func		my_vfprintf_nbr_oct;
t_vfprintf_func		my_vfprintf_nbr_bin;
t_vfprintf_func		my_vfprintf_nbr_hex_l;
t_vfprintf_func		my_vfprintf_nbr_hex_u;
t_vfprintf_func		my_vfprintf_chr;
t_vfprintf_func		my_vfprintf_str;
t_vfprintf_func		my_vfprintf_str_np;
t_vfprintf_func		my_vfprintf_ptr;
t_vfprintf_func		my_vfprintf_wrt;
t_vfprintf_func		my_vfprintf_pct;

#endif /* !MY_VFPRINTF_H_ */
