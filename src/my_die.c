/*
** my_die.c for libmy in /home/arthur.melin/Code/libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Dec  7 21:30:22 2016 Arthur Melin
** Last update Tue Jan 17 23:24:43 2017 Arthur Melin
*/

#include  "my.h"

int	my_die_n(char *err_msg, int n)
{
  my_puterr(err_msg);
  return (n);
}
