/*
** my_fprintf_func_map.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 14 17:03:51 2016 Arthur Melin
** Last update Mon Nov 14 21:42:12 2016 Arthur Melin
*/

#include "my_fprintf.h"

static void	my_fprintf_func_map_put(t_fprintf_func_map *map, int i,
					char chr, t_fprintf_func *func)
{
  map[i].chr = chr;
  map[i].func = func;
}

void	my_fprintf_func_map_fill(t_fprintf_func_map *map)
{
  int	i;

  i = 0;
  my_fprintf_func_map_put(map, i++, 'd', my_fprintf_nbr_dec_s);
  my_fprintf_func_map_put(map, i++, 'i', my_fprintf_nbr_dec_s);
  my_fprintf_func_map_put(map, i++, 'u', my_fprintf_nbr_dec_u);
  my_fprintf_func_map_put(map, i++, 'o', my_fprintf_nbr_oct);
  my_fprintf_func_map_put(map, i++, 'b', my_fprintf_nbr_bin);
  my_fprintf_func_map_put(map, i++, 'x', my_fprintf_nbr_hex_l);
  my_fprintf_func_map_put(map, i++, 'X', my_fprintf_nbr_hex_u);
  my_fprintf_func_map_put(map, i++, 'c', my_fprintf_chr);
  my_fprintf_func_map_put(map, i++, 's', my_fprintf_str);
  my_fprintf_func_map_put(map, i++, 'S', my_fprintf_str_np);
  my_fprintf_func_map_put(map, i++, 'p', my_fprintf_ptr);
  my_fprintf_func_map_put(map, i++, 'n', my_fprintf_wrt);
  my_fprintf_func_map_put(map, i++, '%', my_fprintf_pct);
  my_fprintf_func_map_put(map, i++, 'm', my_fprintf_err);
}
