/*
** my_vfprintf.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 21:13:23 2016 Arthur Melin
** Last update Sat Apr 29 20:10:50 2017 Arthur Melin
*/

#include <my.h>
#include <my_vfprintf.h>

uintmax_t	my_vfprintf_arg_mask(size_t length_modifier)
{
  uintmax_t	mask;

  mask = 0;
  if (length_modifier == 0)
    length_modifier = sizeof(int);
  while (length_modifier--)
    {
      mask <<= 8;
      mask |= 0xFF;
    }
  return (mask);
}

static int		my_vfprintf_do(int fd, const char *str,
				      va_list *args, int *written)
{
  const char		*str_start;
  int			i;
  t_vfprintf_fmt	fmt;
  t_vfprintf_func_map	func_map[13];

  str_start = str++;
  my_memset(&fmt, 0, sizeof(fmt));
  my_vfprintf_parse_flags(&fmt, &str);
  my_vfprintf_parse_width(&fmt, &str, args);
  my_vfprintf_parse_prec(&fmt, &str, args);
  my_vfprintf_parse_length(&fmt, &str);
  fmt.specifier = *str++;
  my_vfprintf_func_map_fill(func_map);
  i = 0;
  while (i < 13)
    {
      if (func_map[i].chr == fmt.specifier)
	{
	  i = func_map[i].func(fd, &fmt, args, written);
	  return (i ? 0 : str - str_start);
	}
      i++;
    }
  return (0);
}

int		my_vfprintf(int fd, const char *fmt, va_list *va)
{
  int		off;
  int		res;

  if (!fmt)
    return (-1);
  res = 0;
  while (*fmt)
    {
      off = 0;
      if (*fmt != '%' ||
	  !(off = my_vfprintf_do(fd, fmt, va, &res)))
	{
	  my_fputc(fd, *fmt);
	  off = 1;
	  res++;
	}
      fmt += off;
    }
  return (res);
}
