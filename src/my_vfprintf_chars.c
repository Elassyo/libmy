/*
** my_vfprintf_chars.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Nov 16 10:59:23 2016 Arthur Melin
** Last update Mon Feb 27 15:07:04 2017 Arthur Melin
*/

#include <my_vfprintf.h>

static size_t	my_strlen_np(char *str)
{
  size_t	res;

  res = 0;
  while (*str)
    {
      res += my_isprint(*str) ? 1 : 4;
      str++;
    }
  return (res);
}

int	my_vfprintf_chr(int fd, t_vfprintf_fmt *fmt,
			va_list *args, int *written_ptr)
{
  int	written;

  written = 0;
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - 1  > 0 && fmt->field_width-- && ++written)
      	my_fputc(fd, ' ');
    }
  my_fputc(fd, va_arg(*args, int));
  written++;
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_fputc(fd, ' ');
  *written_ptr += written;
  return (0);
}

int	my_vfprintf_str(int fd, t_vfprintf_fmt *fmt,
			va_list *args, int *written_ptr)
{
  char	*str;
  int	length;
  int	written;

  if (!(str = va_arg(*args, char *)))
    str = "(null)";
  written = 0;
  length = my_strlen(str);
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - length > 0 && fmt->field_width-- && ++written)
      	my_fputc(fd, ' ');
    }
  my_fputs(fd, str);
  written += length;
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_fputc(fd, ' ');
  *written_ptr += written;
  return (0);
}

int	my_vfprintf_str_np(int fd, t_vfprintf_fmt *fmt,
			   va_list *args, int *written_ptr)
{
  char	*str;
  int	length;
  int	written;

  if (!(str = va_arg(*args, char *)))
    str = "(null)";
  written = 0;
  length = my_strlen_np(str);
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - length > 0 && fmt->field_width-- && ++written)
      	my_fputc(fd, ' ');
    }
  while (*str)
    {
      if (my_isprint(*str) && ++written)
	my_fputc(fd, *str++);
      else
	written += my_fprintf(fd, "\\%03hho", *str++);
    }
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_fputc(fd, ' ');
  *written_ptr += written;
  return (0);
}
