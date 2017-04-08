/*
** my_tolower.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 18:10:57 2017 Arthur Melin
** Last update Sat Apr  8 18:11:47 2017 Arthur Melin
*/

#include <my.h>

int	my_tolower(int c)
{
  return (my_isupper(c) ? c + 32 : c);
}
