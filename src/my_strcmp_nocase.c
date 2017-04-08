/*
** my_strcmp_nocase.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Dec  5 10:54:37 2016 Arthur Melin
*/

#include <my.h>

int	my_strcmp_nocase(const char *s1, const char *s2)
{
  while (*s1 && *s2 && my_tolower(*s1) == my_tolower(*s2))
    {
      s1++;
      s2++;
    }
  return (my_tolower(*s1) - my_tolower(*s2));
}
