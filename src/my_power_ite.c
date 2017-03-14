/*
** my_power_ite.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Nov 16 21:49:14 2016 Arthur Melin
** Last update Tue Mar 14 22:22:58 2017 Arthur Melin
*/

#include <my.h>

long	my_power_ite(int base, int power)
{
  long	res;

  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  res = 1;
  while (power--)
    res *= base;
  return (res);
}
