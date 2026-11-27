# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 14:02:03 by lensauva          #+#    #+#              #
#    Updated: 2026/11/27 20:24:32 by lensauva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ================================ DIRECTORY ================================= #

DIR_SRC			:= src
DIR_SRC_BONUS	:= src_bonus
DIR_INC			:= include
DIR_INC_BONUS	:= include_bonus
DIR_OBJ			:= obj

# ================================ PROJET ==================================== #

NAME			:= libftprintf.a
STAMP_MANDATORY	:= .mandatory
STAMP_BONUS		:= .bonus

# ================================ LIBFT ===================================== #

DIR_LIBFT		:= libft
LIBFT			:= $(DIR_LIBFT)/libft.a

# ================================ FLAGS ===================================== #

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
DEPFLAGS		:= -MMD -MP
INC				:= -I$(DIR_INC) -I$(DIR_LIBFT)
INC_BONUS		:= -I$(DIR_INC_BONUS) -I$(DIR_LIBFT)

# =============================== SOURCES ==================================== #

SRC_FILES		:= ft_printf.c \
				   ft_set_sign.c \
				   ft_set_hex.c \
				   ft_utils_put_1.c \
				   ft_utils_put_2.c \
				   ft_utils_str.c \
				   ft_specifier.c

SRC_FILES_BONUS	:= ft_printf_bonus.c \
				   ft_handle_width_bonus.c \
				   ft_handle_sign_bonus.c \
				   ft_handle_hex_bonus.c \
				   ft_handle_prefix_bonus.c \
				   ft_handle_precision_bonus.c \
				   ft_handle_suffix_bonus.c \
				   ft_utils_nb_bonus.c \
				   ft_utils_put_1_bonus.c \
				   ft_utils_put_2_bonus.c \
				   ft_utils_str_bonus.c \
				   ft_specifier_bonus.c

SRCS			:= $(addprefix $(DIR_SRC)/, $(SRC_FILES))
SRCS_BONUS		:= $(addprefix $(DIR_SRC_BONUS)/, $(SRC_FILES_BONUS))
OBJS			:= $(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)
OBJS_BONUS		:= $(SRCS_BONUS:$(DIR_SRC_BONUS)/%.c=$(DIR_OBJ)/%.o)
DEPS			:= $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

# ================================ REGLES ==================================== #

all: $(NAME)

bonus: $(STAMP_BONUS)

$(NAME): $(STAMP_MANDATORY) $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(STAMP_MANDATORY):
	rm -f $(NAME) $(STAMP_BONUS)
	touch $@

$(STAMP_BONUS): $(OBJS_BONUS) $(LIBFT)
	rm -f $(NAME) $(STAMP_MANDATORY)
	touch $@
	ar rcs $(NAME) $(OBJS_BONUS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC_BONUS)/%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_BONUS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

clean:
	rm -rf $(DIR_OBJ)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME) $(STAMP_MANDATORY) $(STAMP_BONUS)
	$(MAKE) -C $(DIR_LIBFT) fclean

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all bonus clean fclean re
