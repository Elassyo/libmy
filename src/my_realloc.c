/*
** my_realloc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 13:51:14 2016 Arthur Melin
** Last update Thu May 11 14:31:10 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_realloc(void *old_ptr, size_t old_sz,
		    size_t new_sz, size_t elem_sz)
{
  void	*new_ptr;

  if (!(new_ptr = malloc(new_sz * elem_sz)))
    return (NULL);
  if (new_sz < old_sz)
    old_sz = new_sz;
  my_memcpy(new_ptr, old_ptr, old_sz * elem_sz);
  free(old_ptr);
  return (new_ptr);
}
