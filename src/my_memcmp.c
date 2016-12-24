/*
** my_memcmp.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Dec 24 00:54:01 2016 Arthur Melin
** Last update Sat Dec 24 00:59:56 2016 Arthur Melin
*/

#include "my.h"

int	my_memcmp(void *s1, void *s2, int n)
{
  if (n == 0)
    return (0);
  while (n-- && *(unsigned char *)s1 == *(unsigned char *)s2)
    {
      s1++;
      s2++;
    }
  return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
