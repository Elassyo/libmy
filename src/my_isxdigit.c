/*
** my_isxdigit.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 17:41:19 2017 Arthur Melin
** Last update Sat Apr  8 17:42:37 2017 Arthur Melin
*/

#include <my.h>

int	my_isxdigit(int c)
{
  return (my_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}
