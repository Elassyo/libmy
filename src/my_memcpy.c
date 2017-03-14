/*
** my_memcpy.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Tue Mar 14 23:25:18 2017 Arthur Melin
*/

#include <my.h>

void	*my_memcpy(void *dest, void *src, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      ((char *)dest)[i] = ((char *)src)[i];
      i++;
    }
  return (dest);
}
