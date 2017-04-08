/*
** my_strtolower.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 18:17:11 2017 Arthur Melin
** Last update Sat Apr  8 18:17:33 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

char			*my_strtolower(char *s)
{
  register size_t	i;

  i = 0;
  while (s[i])
    {
      s[i] = my_tolower(s[i]);
      i++;
    }
  return (s);
}
