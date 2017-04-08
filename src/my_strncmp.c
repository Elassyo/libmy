/*
** my_strncmp.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

int			my_strncmp(const char *s1, const char *s2, size_t n)
{
  register size_t	i;

  i = 0;
  while (*s1 && *s2 && *s1 == *s2 && i < n)
    {
      if (i++ < n)
	{
	  s1++;
	  s2++;
	}
    }
  return (*s1 - *s2);
}
