/*
** my_die_null.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec 21 13:24:40 2016 Arthur Melin
** Last update Wed Dec 21 13:25:33 2016 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void	*my_die_null(char *err_msg)
{
  my_puterr(err_msg);
  return (NULL);
}
