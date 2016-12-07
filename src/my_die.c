/*
** my_die.c for libmy in /home/arthur.melin/Code/libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Dec  7 21:30:22 2016 Arthur Melin
** Last update Wed Dec  7 21:31:23 2016 Arthur Melin
*/

#include  "my.h"

int	my_die(char *err_msg)
{
  my_puterr(err_msg);
  return (84);
}
