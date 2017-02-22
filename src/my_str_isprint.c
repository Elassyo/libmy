/*
** my_str_isprint.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_str_isprint(char *str)
{
  int	ret;

  ret = 1;
  while (*str)
    {
      if (!my_isprint(*str++))
	ret = 0;
    }
  return (ret);
}
