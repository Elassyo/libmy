/*
** my_show_wordtab.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

int	my_show_wordtab(char **tab)
{
  while (*tab)
    {
      my_puts(*tab++);
      my_putc('\n');
    }
  return (0);
}
