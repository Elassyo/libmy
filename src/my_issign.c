/*
** my_issign.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Tue Mar 14 22:22:38 2017 Arthur Melin
*/

#include <my.h>

int	my_issign(char c)
{
  return (c == '+' || c == '-');
}
