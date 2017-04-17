/*
** my_strtod.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 23:12:57 2017 Arthur Melin
** Last update Mon Apr 17 22:32:26 2017 Arthur Melin
*/

#include <my.h>

static double	my_strtod_dec(char **s)
{
  double	res;
  int		rad;

  res = 0.0;
  while (my_isdigit(**s))
    res = res * 10 + *(*s)++ - '0';
  if (**s == '.' && (*s += 1))
    {
      rad = -1;
      while (my_isdigit(**s))
	res = res + (*(*s)++ - '0') * my_pow(10, rad--);
    }
  if (my_tolower(**s) == 'e' && (*s += 1))
    res *= my_pow(10, my_strtol(*s, s, 10));
  return (res);
}

static double	my_strtod_hex(char **s)
{
  const char	*base;
  double	res;
  double	rad;
  int		rad_sz;

  res = 0.0;
  base = "0123456789abcdef";
  while (my_isxdigit(**s))
    res = res * 16 + (my_strchr(base, my_tolower(*(*s)++)) - base);
  if (**s == '.' && (*s += 1))
    {
      rad = 0.0;
      rad_sz = 0;
      while (my_isxdigit(**s))
	{
	  rad = rad * 16 + (my_strchr(base, my_tolower(*(*s)++)) - base);
	  rad_sz++;
	}
      res += rad / my_pow(16, rad_sz);
    }
  if (my_tolower(**s) == 'p' && (*s += 1))
    res *= my_pow(2, my_strtol(*s, s, 10));
  return (res);
}

double		my_strtod(const char *s, char **endptr)
{
  char		sign;
  double	res;

  res = 0.0;
  sign = 1;
  while (my_isspace(*s))
    s++;
  if (*s == '+' || *s == '-')
    sign = *s++ == '-' ? -1 : 1;
  if ((!my_strncmp_nocase(s, "infinity", 8) && (s += 8)) ||
      (!my_strncmp_nocase(s, "inf", 3) && (s += 3)))
    res = MY_INFINITY;
  else if ((!my_strncmp_nocase(s, "nan", 3) && (s += 3)))
    res = MY_NAN;
  else if ((!my_strncmp_nocase(s, "0x", 2) && (s += 2)))
    res = my_strtod_hex((char **)&s);
  else
    res = my_strtod_dec((char **)&s);
  if (endptr)
    *endptr = (char *)s;
  return (sign * res);
}
