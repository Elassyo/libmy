/*
** my_islower.c for libmy in /home/arthur.melin/Code/__libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_islower(char c)
{
  return ('a' <= c && c <= 'z');
}
