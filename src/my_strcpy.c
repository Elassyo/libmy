/*
** my_strcpy.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strcpy(char *dest, const char *src)
{
  register size_t	i;

  i = 0;
  while (*src)
    dest[i++] = *src++;
  dest[i] = 0;
  return (dest);
}
