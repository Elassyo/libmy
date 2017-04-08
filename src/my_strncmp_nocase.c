/*
** my_strncmp_nocase.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 23:16:24 2017 Arthur Melin
** Last update Sat Apr  8 23:44:11 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

int			my_strncmp_nocase(const char *s1, const char *s2,
					  size_t n)
{
  register size_t	i;

  i = 0;
  while (*s1 && *s2 && my_tolower(*s1) == my_tolower(*s2) && i < n)
    {
      if (++i < n)
	{
	  s1++;
	  s2++;
	}
    }
  return (my_tolower(*s1) - my_tolower(*s2));
}
