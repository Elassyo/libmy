/*
** my_memmove.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Apr 12 13:01:10 2017 Arthur Melin
** Last update Wed Apr 12 13:13:48 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void			*my_memmove(void *dest, const void *src, size_t n)
{
  register size_t	i;

  if (src <= dest && (const char *)dest < (const char *)src + n)
    {
      i = n;
      while (i-- > 0)
	((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    }
  else
    my_memcpy(dest, src, n);
  return (dest);
}
