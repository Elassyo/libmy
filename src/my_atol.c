/*
** my_atoi.c for libmy in /home/arthur.melin/Code/libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Apr  6 16:03:55 2017 Arthur Melin
** Last update Thu Apr  6 17:45:37 2017 Arthur Melin
*/

#include <my.h>

long	my_atol(const char *s)
{
  long	nbr;
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
