/*
** my_vfprintf_parsers.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov 14 16:41:43 2016 Arthur Melin
** Last update Thu Apr  6 22:37:32 2017 Arthur Melin
*/

#include <my_vfprintf.h>

void	my_vfprintf_parse_flags(t_vfprintf_fmt *fmt, const char **str)
{
  while (1)
    {
      if (**str == '-')
	fmt->flag_ljust = 1;
      else if (**str == '+')
	fmt->flag_plus = 1;
      else if (**str == ' ')
	fmt->flag_space = 1;
      else if (**str == '#')
	fmt->flag_hash = 1;
      else if (**str == '0')
	fmt->flag_zero = 1;
      else
	return ;
      (*str)++;
    }
}

void	my_vfprintf_parse_width(t_vfprintf_fmt *fmt, const char **str,
			       va_list *args)
{
  if (**str == '*')
    {
      fmt->field_width = va_arg(*args, int);
      (*str)++;
    }
  else
    while (my_isdigit(**str))
      fmt->field_width = fmt->field_width * 10 + *(*str)++ - '0';
}

void	my_vfprintf_parse_prec(t_vfprintf_fmt *fmt, const char **str,
			      va_list *args)
{
  if (**str == '.')
    {
      if (*++(*str) == '*')
	{
	  fmt->precision = va_arg(*args, int);
	  (*str)++;
	}
      else
	while (my_isdigit(**str))
	  fmt->precision = fmt->precision * 10 + *(*str)++ - '0';
    }
  else
    fmt->precision = -1;
}

void	my_vfprintf_parse_length(t_vfprintf_fmt *fmt, const char **str)
{
  if (**str == 'h' && *(*str + 1) == 'h')
    {
      fmt->length_modifier = sizeof(char);
      (*str)++;
    }
  else if ((**str == 'l' && *(*str + 1) == 'l') || **str == 'L')
    {
      fmt->length_modifier = sizeof(long);
      *str += (**str == 'l' ? 1 : 0);
    }
  else if (**str == 'h')
    fmt->length_modifier = sizeof(short);
  else if (**str == 'l')
    fmt->length_modifier = sizeof(long);
  else if (**str == 'j')
    fmt->length_modifier = sizeof(intmax_t);
  else if (**str == 'z')
    fmt->length_modifier = sizeof(size_t);
  else if (**str == 't')
    fmt->length_modifier = sizeof(ptrdiff_t);
  else
    return ;
  (*str)++;
}
