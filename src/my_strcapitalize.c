/*
** my_strcapitalize.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Sat Apr  8 18:13:46 2017 Arthur Melin
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
      s[i] = in ? my_tolower(s[i]) : my_toupper(s[i]);
      in = my_isalnum(s[i++]);
    }
  return (s);
}
