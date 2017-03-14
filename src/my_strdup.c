/*
** my_strdup.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc(my_strlen(src) + 1);
  if (!dest)
    return (dest);
  return (my_strcpy(dest, src));
}
