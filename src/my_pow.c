/*
** my_pow.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Nov 16 21:49:14 2016 Arthur Melin
** Last update Tue Mar 14 22:22:58 2017 Arthur Melin
*/

#include <my.h>

double		my_pow(double x, unsigned int y)
{
  double	res;

  if (y == 0)
    return (1);
  res = 1.0;
  while (y--)
    res *= x;
  return (res);
}
