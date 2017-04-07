/*
** my_sqrt.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

int	my_sqrt(unsigned int x)
{
  long	h;
  long	l;
  long	m;

  h = x;
  l = 0;
  m = x / 2 + x % 2;
  while (h - l > 1 && m * m != x)
    {
      if (m * m <= x)
      	l = m;
      else
      	h = m;
      m = (l + h) / 2;
    }
  return (m);
}
