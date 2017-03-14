/*
** my_strcmp_uncase.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Dec  5 10:54:37 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

int	my_strcmp_uncase(char *s1, char *s2)
{
  int	ret;
  char	*s1_u;
  char	*s2_u;

  s1_u = my_strdup(s1);
  s2_u = my_strdup(s2);
  s1 = my_strupcase(s1_u);
  s2 = my_strupcase(s2_u);
  while (*s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  ret = *s1 - *s2;
  free(s1_u);
  free(s2_u);
  return (ret);
}
