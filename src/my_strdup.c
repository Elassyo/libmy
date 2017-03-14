/*
** my_strdup.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Tue Mar 14 23:23:49 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

char	*my_strdup(char *src)
{
  char	*dest;

  if (!src)
    return (NULL);
  if (!(dest = malloc(my_strlen(src) + 1)))
    return (NULL);
  return (my_strcpy(dest, src));
}
