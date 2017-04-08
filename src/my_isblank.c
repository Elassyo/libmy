/*
** my_isblank.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 17:32:14 2017 Arthur Melin
** Last update Sat Apr  8 17:32:57 2017 Arthur Melin
*/

#include <my.h>

int	my_isblank(int c)
{
  return (c == '\t' || c == ' ');
}
