/*
** my_fprintf.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 21:13:23 2016 Arthur Melin
** Last update Thu Nov 17 00:28:50 2016 Arthur Melin
*/

#include "my.h"
#include "my_fprintf.h"

uintmax_t	my_fprintf_arg_mask(int length_modifier)
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

static int		my_fprintf_do(int fd, const char *str,
				      va_list *args, int *written)
{
  const char		*str_start;
  int			i;
  t_fprintf_fmt		fmt;
  t_fprintf_func_map	func_map[14];

  str_start = str;
  str++;
  my_memset(&fmt, 0, sizeof(fmt));
  my_fprintf_parse_flags(&fmt, &str);
  my_fprintf_parse_width(&fmt, &str, args);
  my_fprintf_parse_prec(&fmt, &str, args);
  my_fprintf_parse_length(&fmt, &str);
  fmt.specifier = *str++;
  my_fprintf_func_map_fill(func_map);
  i = 0;
  while (i < 14)
    {
      if (func_map[i].chr == fmt.specifier)
      	{
      	  i = func_map[i].func(fd, &fmt, args, written);
      	  return (i ? 0 : str_start - str);
      	}
      i++;
    }
  return (0);
}

int		my_fprintf(int fd, const char *format, ...)
{
  int		off;
  int		written;
  va_list	args;

  if (!format)
    return (-1);
  written = 0;
  va_start(args, format);
  while (*format)
    {
      off = 0;
      if (*format != '%' ||
	  !(off = my_fprintf_do(fd, format, &args, &written)))
	{
	  my_putchar_fd(fd, *format);
	  off = 1;
	  written++;
	}
      format += off;
    }
  va_end(args);
  return (written);
}
