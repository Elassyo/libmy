/*
** my_strcapitalize.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

char	*my_strcapitalize(char *s)
{
  int	i;
  int	in;

  i = 0;
  in = 0;
  while (s[i])
    {
      if (in && my_isupper(s[i]))
	s[i] += 32;
      if (!in && my_islower(s[i]))
	s[i] -= 32;
      in = my_isalnum(s[i++]);
    }
  return (s);
}
