/*
** my_realloc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 13:51:14 2016 Arthur Melin
** Last update Wed Dec  7 13:53:55 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_realloc(void *old_buf, int old_sz, int new_sz, int elm_sz)
{
  void	*new_buf;

  if (!(new_buf = malloc(new_sz * elm_sz)))
    return (NULL);
  my_memcpy(new_buf, old_buf, old_sz * elm_sz);
  free(old_buf);
  return (new_buf);
}
