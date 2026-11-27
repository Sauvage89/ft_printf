# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 14:02:03 by lensauva          #+#    #+#              #
#    Updated: 2026/11/27 12:34:50 by lensauva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ================================ DIRECTORY ==================================== #

DIR_SRC		:= src
DIR_OBJ		:= obj
DIR_INC		:= include

# ================================ PROJET ==================================== #

NAME		:= a.out 
CC			:= cc

# ================================ LIBFT ==================================== #

DIR_LIBFT	:= libft
LIBFT		:= libft.a
LINK_LIBFT	:= ft

# ================================ FLAGS ==================================== #

CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		:= 
CINCLUDE	:= -I$(DIR_INC) -Ilibft -MMD -MP
LDFLAGS		:= -L$(DIR_LIBFT) -l$(LINK_LIBFT)

# =============================== SOURCES ==================================== #

SRC_FILES	:= ft_printf.c \
			   ft_handle_sign.c \
			   ft_handle_hex.c \
			   ft_handle_prefix.c \
			   ft_handle_suffix.c \
			   ft_utils_nb.c \
			   ft_utils_put_1.c \
			   ft_utils_put_2.c \
			   ft_utils_str.c \
			   ft_specifier.c \
			   tester2.c

SRCS		:= $(addprefix $(DIR_SRC)/, $(SRC_FILES))
OBJS		:= $(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)
DEPS		:= $(OBJS:%.o=%.d)

# ================================ REGLES ==================================== #

all: $(NAME)

$(NAME): $(OBJS) $(DIR_LIBFT)/$(LIBFT)
	$(CC) $(CINCLUDE) -o $@ $^ $(LDFLAGS)

$(DIR_LIBFT)/$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c 
	$(CC) $(CFLAGS) $(CINCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
