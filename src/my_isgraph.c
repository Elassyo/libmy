/*
** my_isgraph.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 17:37:05 2017 Arthur Melin
** Last update Sat Apr  8 17:37:40 2017 Arthur Melin
*/

#include <my.h>

int	my_isgraph(int c)
{
  return ('!' <= c && c <= '~');
}
