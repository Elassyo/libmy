/*
** my_strncpy.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strncpy(char *dest, const char *src, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  while (i < n)
    dest[i++] = 0;
  return (dest);
}
