/*
** my_fputs.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <unistd.h>
#include <my.h>

void	my_fputs(int fd, const char *s)
{
  write(fd, s, my_strlen(s));
}
