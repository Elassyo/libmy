/*
** my_strcmp.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

int	my_strcmp(const char *s1, const char *s2)
{
  while (*s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
