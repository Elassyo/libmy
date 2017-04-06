/*
** my_sort_int_tab.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Thu Apr  6 15:44:57 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

void		my_sort_int_tab(int *tab, size_t n)
{
  size_t	i;
  size_t	j;
  size_t	min;

  i = 0;
  while (i < n)
    {
      j = i;
      min = i;
      while (j < n)
	{
	  if (tab[j] < tab[min])
	    min = j;
	  j++;
	}
      my_swap_int(tab + i++, tab + min);
    }
}
