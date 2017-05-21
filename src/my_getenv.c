/*
** my_getenv.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun May 21 19:28:45 2017 Arthur Melin
** Last update Sun May 21 19:44:12 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

extern char	**environ;

char		*my_getenv(const char *name)
{
  int		i;
  size_t	len;

  i = 0;
  len = my_strlen(name);
  while (environ && environ[i])
    {
      if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
	return (environ[i] + len + 1);
      i++;
    }
  return (NULL);
}
