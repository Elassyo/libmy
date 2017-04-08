/*
** my_strncat.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strncat(char *dest, const char *src, size_t n)
{
  size_t		len;
  register size_t	i;

  len = my_strlen(dest);
  i = 0;
  while (src[i] && i < n)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = 0;
  return (dest);
}
