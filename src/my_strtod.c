/*
** my_strtod.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 23:12:57 2017 Arthur Melin
** Last update Thu Apr 13 00:13:23 2017 Arthur Melin
*/

#include <my.h>

double		my_strtod_dec(const char **s)
{
}

double		my_strtod_hex(const char **s)
{
}

double		my_strtod(const char *s, const char **endptr)
{
  char		sign;
  double	res;

  nbr = 0;
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
    res = my_strtod_hex(&s);
  else
    res = my_strtod_dec(&s);
  if (endptr)
    *endptr = s;
  return (sign * res);
}
