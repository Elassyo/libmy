/*
** my_strtod.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 23:12:57 2017 Arthur Melin
** Last update Sat Apr  8 23:14:14 2017 Arthur Melin
*/

#include <my.h>

double		my_strtod(const char *s, const char **endptr)
{
  double	nbr;
  char		sign;

  nbr = 0;
  sign = 1;
  while (my_isspace(*s))
    s++;
  return (sign * nbr);
}
