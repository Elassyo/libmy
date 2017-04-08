/*
** my_rand.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  8 20:47:05 2017 Arthur Melin
** Last update Sat Apr  8 21:43:21 2017 Arthur Melin
*/

#include <stddef.h>
#include <my.h>

static size_t		mt_i;
static unsigned long	mt[312];

void			my_srand(unsigned long seed)
{
  register size_t	i;

  mt[0] = seed;
  i = 0;
  while (i < 311)
    {
      mt[i + 1] = 6364136223846793005 * (mt[i] ^ (mt[i] >> 62)) + (i + 1);
      i++;
    }
  mt_i = 312;
}

unsigned long		my_rand()
{
  unsigned long		x;
  register size_t	i;

  if (mt_i > 312)
    return (0);
  if (mt_i == 312)
    {
      i = 0;
      while (i < 312)
	{
	  x = (mt[i] & 0xffffffff80000000) + (mt[(i + 1) % 312] & 0x7fffffff);
	  x = (x >> 1) ^ (x & 1 ? 0xb5026f5aa96619e9 : 0);
	  mt[i] = mt[(i + 156) % 312] ^ x;
	  i++;
	}
      mt_i = 0;
    }
  x = mt[mt_i++];
  x = x ^ ((x >> 29) & 0x5555555555555555);
  x = x ^ ((x << 17) & 0x71d67fffeda60000);
  x = x ^ ((x << 37) & 0xfff7eee000000000);
  return (x ^ (x >> 43));
}
