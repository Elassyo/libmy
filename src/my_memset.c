/*
** my_memset.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void			*my_memset(void *ptr, int c, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n)
    ((char *)ptr)[i++] = c;
  return (ptr);
}
