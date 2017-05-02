/*
** my_realloc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 13:51:14 2016 Arthur Melin
** Last update Tue May  2 16:36:47 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_realloc(void *src, size_t old, size_t new, size_t element)
{
  void	*res;

  if (!(res = malloc(new * element)))
    return (NULL);
  if (new < old)
    old = new;
  my_memcpy(res, src, old * element);
  free(src);
  return (res);
}
