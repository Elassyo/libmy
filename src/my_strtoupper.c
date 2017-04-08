/*
** my_strtoupper.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 18:17:51 2017 Arthur Melin
** Last update Sat Apr  8 18:17:52 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strtoupper(char *s)
{
  register size_t	i;

  i = 0;
  while (s[i])
    {
      s[i] = my_toupper(s[i]);
      i++;
    }
  return (s);
}
