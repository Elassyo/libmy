/*
** my_fprintf.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Mar  7 11:27:44 2017 Arthur Melin
** Last update Tue Mar  7 11:29:25 2017 Arthur Melin
*/

#include <stdarg.h>
#include <my.h>

int		my_fprintf(int fd, const char *format, ...)
{
  int		ret;
  va_list	va;

  va_start(va, format);
  ret = my_vfprintf(fd, format, &va);
  va_end(va);
  return (ret);
}
