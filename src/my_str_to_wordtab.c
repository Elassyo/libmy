/*
** my_str_to_wordtab.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

static int	my_count_words(const char *s)
{
  int		in;
  int		res;

  in = 0;
  res = 0;
  while (*s)
    {
      if (!in && my_isalnum(*s))
      	res++;
      in = my_isalnum(*s++);
    }
  return (res);
}

static char	*my_worddup(const char *s)
{
  char		*res;
  int		len;

  len = 0;
  while (my_isalnum(s[len]))
    len++;
  if (!(res = malloc(len + 1)))
    return (NULL);
  my_strncpy(res, s, len);
  res[len + 1] = 0;
  return (res);
}

char	**my_str_to_wordtab(const char *s)
{
  int	i;
  int	in;
  char	**res;

  if (!(res = malloc((my_count_words(s) + 1) * sizeof(char *))))
    return (NULL);
  i = 0;
  in = 0;
  while (*s)
    {
      if (!in && my_isalnum(*s))
	res[i++] = my_worddup(s);
      in = my_isalnum(*s++);
    }
  res[i] = NULL;
  return (res);
}
