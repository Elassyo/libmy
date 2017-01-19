/*
** my_free_wordtab.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Jan 19 16:10:40 2017 Arthur Melin
** Last update Thu Jan 19 16:13:40 2017 Arthur Melin
*/

#include <stdlib.h>
#include "my.h"

void	my_free_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i]);
  free(tab);
}
