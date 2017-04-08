/*
** my_strtok.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Apr  6 17:53:06 2017 Arthur Melin
** Last update Thu Apr  6 18:02:39 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

char			*my_strtok(char *s, const char *delimiters)
{
  register size_t	i;
  static char		*st_str = NULL;

  if (!s && !(s = st_str))
    return (NULL);
  while (*s && my_strchr(delimiters, *s))
    s++;
  i = 0;
  while (s[i])
    {
      if (my_strchr(delimiters, s[i]))
	{
	  s[i] = 0;
	  st_str = s + i + 1;
	  return (s);
	}
      else
	i++;
    }
  return (NULL);
}
