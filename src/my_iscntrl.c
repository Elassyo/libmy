/*
** my_iscntrl.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 17:33:42 2017 Arthur Melin
** Last update Sat Apr  8 17:36:33 2017 Arthur Melin
*/

#include <my.h>

int	my_iscntrl(int c)
{
  return (0 <= c && c <= 0x1f);
}
