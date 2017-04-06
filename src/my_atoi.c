/*
** my_atoi.c for libmy in /home/arthur.melin/Code/libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Apr  6 16:03:55 2017 Arthur Melin
** Last update Thu Apr  6 16:06:12 2017 Arthur Melin
*/

#include <my.h>

int	my_atoi(const char *s)
{
  int	nbr;
  char	sign;

  nbr = 0;
  sign = 1;
  while (*s && (*s == '-' || *s == '+'))
    {
      if (*s++ == '-')
	sign *= -1;
    }
  while (*s && my_isdigit(*s))
    nbr = nbr * 10 + *s++ - '0';
  return (sign * nbr);
}
