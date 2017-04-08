/*
** my_strlen.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

size_t			my_strlen(const char *s)
{
  register size_t	res;

  res = 0;
  while (s[res])
    res++;
  return (res);
}
