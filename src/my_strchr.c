/*
** my_strchr.c for libmy in /home/arthur.melin/Code/__libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Dec  7 13:49:53 2016 Arthur Melin
** Last update Wed Dec  7 13:54:19 2016 Arthur Melin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strchr(char *str, char c)
{
  while (*str)
    {
      if (*str == c)
	return (str);
      str++;
    }
  return (NULL);
}
