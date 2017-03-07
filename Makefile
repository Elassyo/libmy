##
## Makefile for libmy in /home/arthur.melin/Code/libmy
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.eu>
##
## Started on  Wed Dec 14 12:30:02 2016 Arthur Melin
## Last update Tue Mar  7 11:35:17 2017 Arthur Melin
##

NAME		=	libmy.a

SRC		=	my_die_n.c		\
			my_die_null.c		\
			my_find_prime_sup.c	\
			my_fprintf.c		\
			my_free_wordtab.c	\
			my_getnbr.c		\
			my_getnbr_base.c	\
			my_iobuf.c		\
			my_is_prime.c		\
			my_isalnum.c		\
			my_isalpha.c		\
			my_islower.c		\
			my_isneg.c		\
			my_isnum.c		\
			my_isprint.c		\
			my_issign.c		\
			my_isupper.c		\
			my_memcmp.c		\
			my_memcpy.c		\
			my_memset.c		\
			my_power_ite.c		\
			my_power_rec.c		\
			my_printf.c		\
			my_putchar_fd.c		\
			my_putnbr.c		\
			my_putnbr_base.c	\
			my_putnchar_fd.c	\
			my_putstr_fd.c		\
			my_read_file.c		\
			my_read_file_bin.c	\
			my_read_line.c		\
			my_realloc.c		\
			my_revstr.c		\
			my_show_wordtab.c	\
			my_sort_int_tab.c	\
			my_square_root.c	\
			my_str_isalpha.c	\
			my_str_islower.c	\
			my_str_isnum.c		\
			my_str_isprint.c	\
			my_str_isupper.c	\
			my_str_to_wordtab.c	\
			my_strcapitalize.c	\
			my_strcat.c		\
			my_strchr.c		\
			my_strcmp.c		\
			my_strcmp_uncase.c	\
			my_strcpy.c		\
			my_strdup.c		\
			my_strlen.c		\
			my_strlowcase.c		\
			my_strncat.c		\
			my_strncmp.c		\
			my_strncpy.c		\
			my_strstr.c		\
			my_strupcase.c		\
			my_swap.c		\
			my_vfprintf.c		\
			my_vfprintf_chars.c	\
			my_vfprintf_func_map.c	\
			my_vfprintf_misc.c	\
			my_vfprintf_nbr.c	\
			my_vfprintf_nbr_bases.c	\
			my_vfprintf_nbr_dec.c	\
			my_vfprintf_parsers.c	\
			my_wordtab_len.c
INC		=	my.h			\
			my_iobuf.h		\
			my_vfprintf.h
OBJ		=	$(SRC:.c=.o)

SRCDIR		=	src
INCDIR		=	src
OBJDIR		=	obj

DIST_INC	=	my.h
DIST_INCDIR	=	../../include

CC		=	gcc
CFLAGS		=	-c -O2 -W -Wall -Wextra -std=c89 -pedantic
AR		=	ar -rc
CP		=	cp
MKDIR		=	mkdir -p
RM		=	rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(AR) $@ $^

dist: $(NAME) | $(DIST_INCDIR) clean
	$(CP) $(INCDIR)/$(DIST_INC) $(DIST_INCDIR)/
	$(RM) .git

$(DIST_INCDIR):
	$(MKDIR) $(DIST_INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(INCDIR)/, $(INC)) | $(OBJDIR)
	$(CC) $< $(CFLAGS) -o $@

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dist clean fclean re
