/*
** my_word_tab_len.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Jan 19 16:04:22 2017 Arthur Melin
** Last update Thu Jan 19 16:05:12 2017 Arthur Melin
*/

#include "my.h"

int	my_word_tab_len(char **tab)
{
  int	len;

  len = 0;
  while (tab[len])
    len++;
  return (len);
}
