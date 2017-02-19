/*
** my_putnchar_fd.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun Feb 19 22:55:05 2017 Arthur Melin
** Last update Sun Feb 19 22:58:11 2017 Arthur Melin
*/

#include <unistd.h>
#include "my.h"

void	my_putnchar_fd(int fd, char c, int n)
{
  while (n--)
    write(fd, &c, 1);
}
