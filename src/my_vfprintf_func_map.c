/*
** my_vfprintf_func_map.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov 14 17:03:51 2016 Arthur Melin
** Last update Mon Feb 27 15:07:45 2017 Arthur Melin
*/

#include "my_vfprintf.h"

static void	my_vfprintf_func_map_put(t_vfprintf_func_map *map, int i,
					char chr, t_vfprintf_func *func)
{
  map[i].chr = chr;
  map[i].func = func;
}

void	my_vfprintf_func_map_fill(t_vfprintf_func_map *map)
{
  int	i;

  i = 0;
  my_vfprintf_func_map_put(map, i++, 'd', my_vfprintf_nbr_dec_s);
  my_vfprintf_func_map_put(map, i++, 'i', my_vfprintf_nbr_dec_s);
  my_vfprintf_func_map_put(map, i++, 'u', my_vfprintf_nbr_dec_u);
  my_vfprintf_func_map_put(map, i++, 'o', my_vfprintf_nbr_oct);
  my_vfprintf_func_map_put(map, i++, 'b', my_vfprintf_nbr_bin);
  my_vfprintf_func_map_put(map, i++, 'x', my_vfprintf_nbr_hex_l);
  my_vfprintf_func_map_put(map, i++, 'X', my_vfprintf_nbr_hex_u);
  my_vfprintf_func_map_put(map, i++, 'c', my_vfprintf_chr);
  my_vfprintf_func_map_put(map, i++, 's', my_vfprintf_str);
  my_vfprintf_func_map_put(map, i++, 'S', my_vfprintf_str_np);
  my_vfprintf_func_map_put(map, i++, 'p', my_vfprintf_ptr);
  my_vfprintf_func_map_put(map, i++, 'n', my_vfprintf_wrt);
  my_vfprintf_func_map_put(map, i++, '%', my_vfprintf_pct);
}
