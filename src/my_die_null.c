/*
** my_die_null.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec 21 13:24:40 2016 Arthur Melin
** Last update Wed Apr 26 20:14:40 2017 Arthur Melin
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <my.h>

void	*my_die_null(const char *fmt, ...)
{
  va_list	va;

  va_start(va, fmt);
  my_vfprintf(STDERR_FILENO, fmt, &va);
  va_end(va);
  return (NULL);
}
