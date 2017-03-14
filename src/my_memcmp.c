/*
** my_memcmp.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Dec 24 00:54:01 2016 Arthur Melin
** Last update Tue Dec 27 23:46:16 2016 Arthur Melin
*/

#include <my.h>

int	my_memcmp(void *s1, void *s2, int n)
{
  int	v;

  v = 0;
  while (n-- && v == 0)
    v = *(unsigned char *)s1 - *(unsigned char *)s2;
  return (v);
}
