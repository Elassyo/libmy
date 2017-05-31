/*
** my_die_n.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Dec  7 21:30:22 2016 Arthur Melin
** Last update Wed Apr 26 20:12:20 2017 Arthur Melin
*/

#include <stdarg.h>
#include <unistd.h>
#include <my.h>

int		my_die_n(int n, const char *fmt, ...)
{
  va_list	va;

  va_start(va, fmt);
  my_vfprintf(STDERR_FILENO, fmt, &va);
  va_end(va);
  return (n);
}
