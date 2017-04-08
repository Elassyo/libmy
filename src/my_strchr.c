/*
** my_strchr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 13:49:53 2016 Arthur Melin
** Last update Sun Dec 18 12:45:02 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

const char	*my_strchr(const char *s, int c)
{
  while (*s)
    {
      if (*s == c)
      	return (s);
      s++;
    }
  return (NULL);
}
