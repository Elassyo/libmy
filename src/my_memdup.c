/*
** my_memdup.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Mar 14 23:21:35 2017 Arthur Melin
** Last update Tue Mar 14 23:25:30 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_memdup(void *src, int size)
{
  void	*dest;

  if (!src)
    return (NULL);
  if (!(dest = malloc(size)))
    return (NULL);
  return (my_memcpy(dest, src, size));
}
