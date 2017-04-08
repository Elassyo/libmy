/*
** my_strrev.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strrev(char *s)
{
  size_t		len;
  size_t		hlen;
  register size_t	i;

  len = my_strlen(s);
  hlen = len / 2;
  i = 0;
  while (i < hlen)
    {
      my_swap_char(s + i, s + len - i - 1);
      i++;
    }
  return (s);
}
