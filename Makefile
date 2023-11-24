# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:48:20 by aurban            #+#    #+#              #
#    Updated: 2023/11/24 13:18:20 by aurban           ###   ########.fr        #
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

OPERATIONS_FILES_PATH=operations

SRC_FILES:=main.c baby_sort.c help_messages.c

OPERATIONS_FILES:= stack_push.c stack_rotate_inverse.c stack_rotate.c stack_swap.c
OPERATIONS_FILES:= $(addprefix $(OPERATIONS_FILES_PATH)/,$(OPERATIONS_FILES))
SRC_FILES+=$(OPERATIONS_FILES)


SRC_FILES:= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
SRC_OBJECTS:= $(patsubst %.c,%.o,$(SRC_FILES))

$(LIBFT):
	@make -C $(LIBFT_PATH)/ all
	@make -C $(LIBFT_PATH)/ clean
	@mv $(LIBFT_PATH)/$@ ./

all: $(LIBFT) $(NAME)

DO_LIBS: $(LIBFT)

$(NAME): $(SRC_OBJECTS)
	$(CC) $^ $(LIBFT) $(CFLAGS) -o $@

clean: 
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME) $(LIBFT) 

re: fclean all

.PHONY: all clean fclean re libft DO_LIBS