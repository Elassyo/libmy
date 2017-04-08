/*
** my_isspace.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 23:02:34 2017 Arthur Melin
** Last update Sat Apr  8 23:03:48 2017 Arthur Melin
*/

#include <my.h>

int	my_isspace(int c)
{
  return (c == ' ' || ('\t' <= c && c <= '\r'));
}
