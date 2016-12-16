##
## Makefile for libmy in /home/arthur.melin/Code/libmy
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.eu>
##
## Started on  Wed Dec 14 12:30:02 2016 Arthur Melin
## Last update Wed Dec 14 12:31:51 2016 Arthur Melin
##

NAME		=	libmy.a

SRC		=	my_die.c		\
			my_find_prime_sup.c	\
			my_getnbr_base.c	\
			my_getnbr.c		\
			my_iobuf.c		\
			my_isalnum.c		\
			my_isalpha.c		\
			my_islower.c		\
			my_isneg.c		\
			my_isnum.c		\
			my_is_prime.c		\
			my_isprintable.c	\
			my_issign.c		\
			my_isupper.c		\
			my_math.c		\
			my_memcpy.c		\
			my_memset.c		\
			my_power_ite.c		\
			my_power_rec.c		\
			my_printf.c		\
			my_printf_chars.c	\
			my_printf_func_map.c	\
			my_printf_misc.c	\
			my_printf_nbr_bases.c	\
			my_printf_nbr.c		\
			my_printf_nbr_dec.c	\
			my_printf_parsers.c	\
			my_putchar_fd.c		\
			my_putchar_hex.c	\
			my_putnbr_base.c	\
			my_put_nbr.c		\
			my_putstr_fd.c		\
			my_read_file_bin.c	\
			my_read_file.c		\
			my_realloc.c		\
			my_revstr.c		\
			my_showmem.c		\
			my_showstr.c		\
			my_show_wordtab.c	\
			my_sort_int_tab.c	\
			my_square_root.c	\
			my_strcapitalize.c	\
			my_strcat.c		\
			my_strchr.c		\
			my_strcmp.c		\
			my_strcmp_uncase.c	\
			my_strcpy.c		\
			my_strdup.c		\
			my_str_isalpha.c	\
			my_str_islower.c	\
			my_str_isnum.c		\
			my_str_isprintable.c	\
			my_str_isupper.c	\
			my_strlen.c		\
			my_strlowcase.c		\
			my_strncat.c		\
			my_strncmp.c		\
			my_strncpy.c		\
			my_strstr.c		\
			my_str_to_wordtab.c	\
			my_strupcase.c		\
			my_swap.c
INC		=	my.h			\
			my_iobuf.h		\
			my_printf.h
OBJ		=	$(SRC:.c=.o)

SRCDIR		=	src
INCDIR		=	src
OBJDIR		=	obj

DIST_INC	=	my.h
DIST_INCDIR	=	../../include

CC		=	gcc
CFLAGS		=	-c -O2 -W -Wall -Wextra
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
