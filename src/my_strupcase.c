/*
** my_strupcase.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

char			*my_strupcase(char *s)
{
  register size_t	i;

  i = 0;
  while (s[i])
    {
      if (my_islower(s[i]))
	s[i] -= 32;
      i++;
    }
  return (s);
}
