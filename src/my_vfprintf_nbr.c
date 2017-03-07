/*
** my_vfprintf_nbr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Nov 15 17:04:47 2016 Arthur Melin
** Last update Thu Nov 17 00:33:25 2016 Arthur Melin
*/

#include "my_vfprintf.h"

int		my_vfprintf_nbr_length(t_vfprintf_fmt *fmt, uintmax_t nbr,
				      int base_length)
{
  int		length;

  if (nbr == 0 && fmt->precision != 0)
    return (1);
  length = 0;
  while (nbr)
    {
      nbr /= base_length;
      length++;
    }
  return (length);
}

int	my_vfprintf_nbr_digits(int fd, t_vfprintf_nbr_fmt *nbr_fmt,
			      uintmax_t nbr, int written)
{
  int	len;
  int	padding;
  int	base_len;

  base_len = my_strlen(nbr_fmt->base);
  len = my_vfprintf_nbr_length(nbr_fmt->fmt, nbr, base_len);
  if (!nbr_fmt->fmt->flag_ljust && nbr_fmt->fmt->flag_zero &&
      nbr_fmt->fmt->precision == -1)
    padding = nbr_fmt->fmt->field_width - len;
  else
    padding = nbr_fmt->fmt->precision - len;
  while (padding-- > 0 && ++written)
    my_putchar_fd(fd, nbr_fmt->base[0]);
  while (len-- && ++written)
    my_putchar_fd(fd, nbr_fmt->base[nbr / my_power_ite(base_len, len) %
    				    base_len]);
  return (written);
}

int		my_vfprintf_nbr(int fd, t_vfprintf_nbr_fmt *nbr_fmt,
			       uintmax_t nbr, int *written_ptr)
{
  int		length;
  int		padding;
  int		written;

  length = my_vfprintf_nbr_length(nbr_fmt->fmt, nbr, my_strlen(nbr_fmt->base));
  length += nbr_fmt->fmt->flag_hash ? my_strlen(nbr_fmt->prefix) : 0;
  written = 0;
  if (!nbr_fmt->fmt->flag_ljust && !nbr_fmt->fmt->flag_zero)
    {
      padding = nbr_fmt->fmt->field_width -
		MY_MAX(length, nbr_fmt->fmt->precision);
      while (padding-- > 0 && ++written)
	my_putchar_fd(fd, ' ');
    }
  if (nbr_fmt->fmt->flag_hash)
    {
      my_putstr_fd(fd, nbr_fmt->prefix);
      written += my_strlen(nbr_fmt->prefix);
    }
  written = my_vfprintf_nbr_digits(fd, nbr_fmt, nbr, written);
  while (nbr_fmt->fmt->flag_ljust &&
  	 written < nbr_fmt->fmt->field_width && ++written)
    my_putchar_fd(fd, ' ');
  *written_ptr += written;
  return (0);
}
