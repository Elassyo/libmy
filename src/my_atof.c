/*
** my_atof.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Apr  6 17:44:49 2017 Arthur Melin
** Last update Wed Apr 12 13:16:22 2017 Arthur Melin
*/

#include <my.h>

double	my_atof(const char *s)
{
  return (my_strtod(s, NULL));
}
