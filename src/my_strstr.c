/*
** my_strstr.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include <my.h>

const char	*my_strstr(const char *haystack, const char *needle)
{
  size_t	len;

  if (!(len = my_strlen(needle)))
    return (haystack);
  while (*haystack && my_strncmp(haystack, needle, len))
    haystack++;
  if (*haystack)
    return (haystack);
  return (NULL);
}
