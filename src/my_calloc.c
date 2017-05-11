/*
** my_calloc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu May 11 14:24:38 2017 Arthur Melin
** Last update Thu May 11 14:27:18 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_calloc(size_t size)
{
  void	*res;

  if (!(res = malloc(size)))
    return (NULL);
  return (my_memset(res, 0, size));
}
