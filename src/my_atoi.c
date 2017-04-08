/*
** my_atoi.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 22:29:16 2017 Arthur Melin
** Last update Sat Apr  8 22:33:08 2017 Arthur Melin
*/

#include <my.h>

int	my_atoi(const char *s)
{
  return (my_strtol(s, NULL, 10));
}
