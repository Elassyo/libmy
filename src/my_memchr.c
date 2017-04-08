/*
** my_memchr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 13:49:53 2016 Arthur Melin
** Last update Thu Apr  6 23:03:27 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

const void		*my_memchr(const void *s, int c, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n)
    {
      if (*((char *)s + i) == c)
      	return ((char *)s + i);
      i++;
    }
  return (NULL);
}
