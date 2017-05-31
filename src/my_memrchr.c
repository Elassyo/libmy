/*
** my_memrchr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Fri Apr  7 17:35:38 2017 Arthur Melin
** Last update Fri Apr  7 17:37:14 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

const void		*my_memrchr(const void *s, int c, size_t n)
{
  register size_t	i;
  const void		*res;

  res = NULL;
  i = 0;
  while (i < n)
    {
      if (*((char *)s + i) == c)
	res = (char *)s + i;
      i++;
    }
  return (res);
}
