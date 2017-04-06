/*
** my_memcpy.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Tue Mar 14 23:25:18 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void			*my_memcpy(void *dest, const void *src, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n)
    {
      ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
      i++;
    }
  return (dest);
}
