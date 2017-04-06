/*
** my_putnbr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

int	my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putc('-');
      nbr = -nbr;
    }
  if (nbr > 10)
    my_putnbr(nbr / 10);
  my_putc('0' + nbr % 10);
  return (0);
}
