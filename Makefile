##
## Makefile for libmy in /home/arthur.melin/Code/libmy
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.eu>
##
## Started on  Wed Dec 14 12:30:02 2016 Arthur Melin
## Last update Sat Apr  8 21:43:39 2017 Arthur Melin
##

NAME		=	libmy.a

SRCS		=	my_atof.c		\
			my_atoi.c		\
			my_atol.c		\
			my_die_n.c		\
			my_die_null.c		\
			my_fprintf.c		\
			my_fputc.c		\
			my_fputnc.c		\
			my_fputs.c		\
			my_free_wordtab.c	\
			my_iobuf.c		\
			my_isalnum.c		\
			my_isalpha.c		\
			my_isdigit.c		\
			my_islower.c		\
			my_isprint.c		\
			my_isupper.c		\
		        my_isblank.c		\
		        my_iscntrl.c		\
		        my_isgraph.c		\
		        my_ispunct.c		\
		        my_isxdigit.c		\
			my_memchr.c		\
			my_memcmp.c		\
			my_memcpy.c		\
			my_memdup.c		\
			my_memrchr.c		\
			my_memset.c		\
			my_pow.c		\
			my_printf.c		\
			my_rand.c		\
			my_read_file_bin.c	\
			my_read_file.c		\
			my_read_line.c		\
			my_realloc.c		\
			my_show_wordtab.c	\
			my_sort_int_tab.c	\
			my_sqrt.c		\
			my_strcapitalize.c	\
			my_strcat.c		\
			my_strchr.c		\
			my_strcmp.c		\
			my_strcmp_nocase.c	\
			my_strcpy.c		\
			my_strdup.c		\
			my_str_isalpha.c	\
			my_str_isdigit.c	\
			my_str_islower.c	\
			my_str_isprint.c	\
			my_str_isupper.c	\
			my_strlen.c		\
			my_strncat.c		\
			my_strncmp.c		\
			my_strncpy.c		\
			my_strrev.c		\
			my_strrchr.c		\
			my_strstr.c		\
			my_strtok.c		\
			my_strtolower.c		\
			my_strtoupper.c		\
			my_str_to_wordtab.c	\
			my_swap.c		\
			my_tolower.c		\
			my_toupper.c		\
			my_vfprintf.c		\
			my_vfprintf_chars.c	\
			my_vfprintf_func_map.c	\
			my_vfprintf_misc.c	\
			my_vfprintf_nbr_bases.c	\
			my_vfprintf_nbr.c	\
			my_vfprintf_nbr_dec.c	\
			my_vfprintf_parsers.c	\
			my_wordtab_len.c
INCS		=	my.h		\
			my_iobuf.h	\
			my_vfprintf.h
OBJS		=	$(SRCS:.c=.o)

SRCSDIR		=	src
INCSDIR		=	include
OBJSDIR		=	obj

DIST_INCS	=	my.h
DIST_INCSDIR	=	../../include

CC		=	gcc
CFLAGS		=	-c -I$(INCSDIR) -O2 -W -Wall -Wextra -std=c89 -pedantic
AR		=	ar -rc
CP		=	cp
MKDIR		=	mkdir -p
RM		=	rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJSDIR)/, $(OBJS))
	$(AR) $@ $^

dist: $(NAME) | $(DIST_INCSDIR) clean
	$(CP) $(addprefix $(INCSDIR)/,$(DIST_INCS)) $(DIST_INCSDIR)/
	$(RM) .git
	$(RM) README.md

$(DIST_INCSDIR):
	$(MKDIR) $@

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(addprefix $(INCSDIR)/,$(INCS)) | $(OBJSDIR)
	$(CC) $< $(CFLAGS) -o $@

$(OBJSDIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dist clean fclean re
