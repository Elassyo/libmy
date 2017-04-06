/*
** my_swap.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Thu Apr  6 15:50:06 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

int	my_swap(void *a, void *b, size_t n)
{
  void	*tmp;

  if (!a || !b)
    return (1);
  if (!(tmp = my_memdup(a, n)))
    return (1);
  my_memcpy(a, b, n);
  my_memcpy(b, tmp, n);
  free(tmp);
  return (0);
}
