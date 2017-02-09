/*
** my_strchr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Dec  7 13:49:53 2016 Arthur Melin
** Last update Sun Dec 18 12:45:02 2016 Arthur Melin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strchr(char *str, char c)
{
  while (1)
    {
      if (*str == c)
	return (str);
      if (!*str)
	return (NULL);
      str++;
    }
  return (NULL);
}
