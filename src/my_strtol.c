/*
** my_strtoi.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 22:26:44 2017 Arthur Melin
** Last update Mon Apr 17 18:30:51 2017 Arthur Melin
*/

#include <stdlib.h>
#include <my.h>

static int	base_detect(const char **s, int base)
{
  if (base == 0)
    {
      if (**s == '0')
	base = my_strncmp_nocase(*s, "0x", 2) ? 8 : 16;
      else
	return (10);
    }
  if (base == 16 && !my_strncmp_nocase(*s, "0x", 2))
    (*s) += 2;
  return (base);
}

long	my_strtol(const char *s, char **endptr, int base)
{
  long	nbr;
  char	sign;
  char	*bases;

  nbr = 0;
  sign = 1;
  while (my_isspace(*s))
    s++;
  if (*s == '+' || *s == '-')
    sign = *s++ == '-' ? -1 : 1;
  base = base_detect(&s, base);
  if (base && (base < 2 || base > 36))
    return (0);
  bases = my_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
  bases[base] = 0;
  while (*s && my_strchr(bases, my_tolower(*s)))
    nbr = nbr * base + my_strchr(bases, my_tolower(*s++)) - bases;
  free(bases);
  if (endptr)
    *endptr = (char *)s;
  return (sign * nbr);
}
