# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 18:27:40 by guhernan          #+#    #+#              #
#    Updated: 2021/03/09 10:50:14 by guhernan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CMDS	=	ar -rcs
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a 
LIB		=	libft.h
RM		=	rm -f
OBJ_DIR =	../../objs
OBJ_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJ) ) 
BONUS_PATH =	$(addprefix $(OBJ_DIR)/, $(BOBJ) ) 
VPATH	=	$(OBJ_DIR) $(AR_DIR)
OBJ		=	$(SRCS:.c=.o)
BOBJ	=	$(BONUS:.c=.o)
SRCS	=	ft_atoi.c \
ft_uatoi.c \
ft_bzero.c \
ft_calloc.c \
ft_dbl_chrcalloc.c \
ft_count_base.c \
ft_count_split.c \
ft_scount_base.c \
ft_free.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_isstr.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdup.c \
ft_memjoin.c \
ft_memmove.c \
ft_memset.c \
ft_memrset.c \
ft_realloc.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strcmp.c \
ft_strnstr.c \
ft_strnstr_nb.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strrpl.c \
ft_split.c \
ft_itoa.c \
ft_uitoa.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_putnbr_base.c

BONUS	=	ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstcleanlst.c \
ft_lstdelone.c \
ft_lstdelone_lst.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c  \
ft_lstsize.c

all:		$(NAME)

$(NAME):	$(OBJ) $(BOBJ)
			$(CMDS) $(NAME) $(OBJ_PATH) $(BONUS_PATH)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

bonus:		$(NAME)

%.o :		%.c $(LIB) | $(OBJ_DIR)
			$(CC) $(CFLAGS) -o $(OBJ_DIR)/$@ -c $<

.PHONY :	fclean clean re all

clean :
			$(RM) $(OBJ_PATH) $(BONUS_PATH)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all
