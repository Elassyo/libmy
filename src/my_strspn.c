/*
** my_strspn.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Apr 17 17:08:34 2017 Arthur Melin
** Last update Mon Apr 17 17:10:55 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

size_t			my_strspn(const char *s1, const char *s2)
{
  register size_t	i;

  i = 0;
  while (s1[i] && my_strchr(s2, s1[i]))
    i++;
  return (i);
}
