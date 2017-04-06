/*
** my_memcmp.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Dec 24 00:54:01 2016 Arthur Melin
** Last update Tue Dec 27 23:46:16 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

int			my_memcmp(const void *s1, const void *s2, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
    i++;
  return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
