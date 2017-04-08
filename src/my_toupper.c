/*
** my_toupper.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 18:11:57 2017 Arthur Melin
** Last update Sat Apr  8 18:12:47 2017 Arthur Melin
*/

#include <my.h>

int	my_toupper(int c)
{
  return (my_islower(c) ? c - 32 : c);
}
