# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 14:02:03 by lensauva          #+#    #+#              #
#    Updated: 2026/11/28 21:08:59 by lensauva         ###   ########lyon.fr    #
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

# ================================ FLAGS ===================================== #

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
DEPFLAGS		:= -MMD -MP
INC				:= -I$(DIR_INC)
INC_BONUS		:= -I$(DIR_INC_BONUS)

# =============================== SOURCES ==================================== #

SRC_FILES		:= ft_printf.c \
				   ft_set_sign.c \
				   ft_set_hex.c \
				   ft_utils_put_1.c \
				   ft_utils_put_2.c \
				   ft_utils_str.c \
				   ft_specifier.c

SRC_FILES_BONUS	:= ft_printf_bonus.c \
				   ft_set_bonus.c \
				   ft_set_hex_bonus.c \
				   ft_set_prefix_bonus.c \
				   ft_set_sign_bonus.c \
				   ft_set_suffix_bonus.c \
				   ft_set_width_bonus.c \
				   ft_utils_nb_1_bonus.c \
				   ft_utils_nb_2_bonus.c \
				   ft_utils_put_1_bonus.c \
				   ft_utils_put_2_bonus.c \
				   ft_utils_put_3_bonus.c \
				   ft_utils_str_1_bonus.c \
				   ft_utils_str_2_bonus.c

SRCS			:= $(addprefix $(DIR_SRC)/, $(SRC_FILES))
SRCS_BONUS		:= $(addprefix $(DIR_SRC_BONUS)/, $(SRC_FILES_BONUS))
OBJS			:= $(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)
OBJS_BONUS		:= $(SRCS_BONUS:$(DIR_SRC_BONUS)/%.c=$(DIR_OBJ)/%.o)
DEPS			:= $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

# ================================ REGLES ==================================== #

all: $(NAME)

bonus: $(STAMP_BONUS)

$(NAME): $(STAMP_MANDATORY) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(STAMP_MANDATORY):
	rm -f $(NAME) $(STAMP_BONUS)
	touch $@

$(STAMP_BONUS): $(OBJS_BONUS)
	rm -f $(NAME) $(STAMP_MANDATORY)
	touch $@
	ar rcs $(NAME) $(OBJS_BONUS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC_BONUS)/%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_BONUS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME) $(STAMP_MANDATORY) $(STAMP_BONUS)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all bonus clean fclean re
