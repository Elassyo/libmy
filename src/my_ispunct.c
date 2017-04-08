/*
** my_ispunct.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 17:38:08 2017 Arthur Melin
** Last update Sat Apr  8 17:40:58 2017 Arthur Melin
*/

#include <my.h>

int	my_ispunct(int c)
{
  return (('!' <= c && c <= '/') || (':' <= c && c <= '@') ||
	  ('[' <= c && c <= '`') || ('{' <= c && c <= '~'));
}
