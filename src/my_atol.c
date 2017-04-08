/*
** my_atol.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 22:31:33 2017 Arthur Melin
** Last update Sat Apr  8 22:32:15 2017 Arthur Melin
*/

#include <my.h>

long	my_atol(const char *s)
{
  return (my_strtol(s, NULL, 10));
}
