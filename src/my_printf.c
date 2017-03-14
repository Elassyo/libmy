/*
** my_printf.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Mar  7 11:08:49 2017 Arthur Melin
** Last update Tue Mar  7 11:29:37 2017 Arthur Melin
*/

#include <stdarg.h>
#include <unistd.h>
#include <my.h>

int		my_printf(const char *format, ...)
{
  int		ret;
  va_list	va;

  va_start(va, format);
  ret = my_vfprintf(STDOUT_FILENO, format, &va);
  va_end(va);
  return (ret);
}
