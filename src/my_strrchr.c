/*
** my_strrchr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Fri Apr  7 17:16:39 2017 Arthur Melin
** Last update Fri Apr  7 17:17:49 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

const char	*my_strrchr(const char *s, int c)
{
  const char	*res;

  res = NULL;
  while (*s)
    {
      if (*s == c)
	res = s;
      s++;
    }
  return (res);
}
