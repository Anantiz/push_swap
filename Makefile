# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:48:20 by aurban            #+#    #+#              #
#    Updated: 2023/12/01 21:23:51 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
INCLUDE_PATH=./includes
CFLAGS:=-Wall -Werror -Wextra -I$(INCLUDE_PATH) -g3 -fsanitize=address
RM:=rm -rf

NAME:=push_swap
LIBFT=libft.a

SRC_PATH:=./src
LIBFT_PATH:=./libft

SRC_FILES:=main_push_swap.c

OPERATIONS_FILES_PATH=operations
OPERATIONS_FILES:= stack_push.c stack_rotate_inverse.c stack_rotate.c stack_swap.c undo_logs.c
OPERATIONS_FILES:= $(addprefix $(OPERATIONS_FILES_PATH)/,$(OPERATIONS_FILES))

UTILS_FILES_PATH=utils
UTILS_FILES:= check_sort.c check_duplicates.c fcking_layers.c various_utils.c
UTILS_FILES:=$(addprefix $(UTILS_FILES_PATH)/,$(UTILS_FILES))

SORT_FILES_PATH=sort
SORT_FILES:= baby_sort.c sortzilla.c ft_quicksort.c give_indexes.c\
	sortzilla_utils.c	sortzilla_layersort.c	sortzilla_get_cost.c
SORT_FILES:=$(addprefix $(SORT_FILES_PATH)/,$(SORT_FILES))

SRC_FILES+=$(OPERATIONS_FILES)
SRC_FILES+=$(UTILS_FILES)
SRC_FILES+=$(SORT_FILES)

SRC_FILES:= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
SRC_OBJECTS:= $(patsubst %.c,%.o,$(SRC_FILES))

SRC_FILES_BONUS:=main_checker_bonus.c

SRC_FILES_BONUS+=$(OPERATIONS_FILES)
SRC_FILES_BONUS+=$(UTILS_FILES)

SRC_PATH_BONUS:=$(SRC_PATH)/bonus
SRC_FILES_BONUS:= $(addprefix $(SRC_PATH_BONUS)/,$(SRC_FILES_BONUS))
BONUS_OBJ:= $(patsubst %.c,%.o,$(SRC_FILES_BONUS))

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	@make -C $(LIBFT_PATH)
	@$(CC) $^ -L$(LIBFT_PATH) -lft $(CFLAGS) -o $@

bonus: $(BONUS_OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $^ -L$(LIBFT_PATH) -lft $(CFLAGS) -o $@

both: $(NAME) bonus

clean:
	@make -C $(LIBFT_PATH)/ clean
	@$(RM) $(SRC_OBJECTS) $(BONUS_OBJ)

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@$(RM) $(NAME) $(LIBFT) $(BONUS)

re: fclean all

.PHONY: all clean fclean re libft bonus push_swap