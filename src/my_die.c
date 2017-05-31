/*
** my_die.c for libjson in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Apr 26 20:12:31 2017 Arthur Melin
** Last update Wed Apr 26 20:12:57 2017 Arthur Melin
*/

#include <stdarg.h>
#include <unistd.h>
#include <my.h>

int		my_die(const char *fmt, ...)
{
  va_list	va;

  va_start(va, fmt);
  my_vfprintf(STDERR_FILENO, fmt, &va);
  va_end(va);
  return (84);
}
