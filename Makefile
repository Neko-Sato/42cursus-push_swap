# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:24:52 by hshimizu          #+#    #+#              #
#    Updated: 2023/10/12 13:41:17 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker

DIR				= .
FT				= $(DIR)/libft
INCS_DIR		= $(DIR)/incs
OBJS_DIR		= $(DIR)/objs

MAIN			= $(DIR)/main.c
BONUS_MAIN		= $(DIR)/main_bonus.c

SRCS			= \
	$(addprefix $(DIR)/srcs/, \
		stackset.c \
		print_stack.c \
		actions.c \
		actions_p.c \
		actions_s.c \
		actions_r.c \
		actions_rr.c \
		optimized_action.c \
		actions_buff.c \
		small_sort.c \
		insert_sort.c \
		quick_sort.c \
		sort_utils.c \
		compress_array.c \
		array_str2nbr.c \
		push_swap.c \
		actions_from_stdin.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS			= -Wall -Wextra -Werror
# CFLAGS			+= -g
CFLAGS			+= -O2
LDFLAGS			+= -L$(FT)
IDFLAGS			+= -I$(FT)
LIBS			+= -lft
IDFLAGS			+= -I$(INCS_DIR)

.PHONY: all clean fclean re bonus

all: $(FT) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

bonus: $(BONUS_MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $(BONUS_NAME) $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(BONUS_MAIN) $(SRCS) $(INCS_DIR)
	@norminette $^

.PHONY: $(FT)
$(FT):
	@git submodule update --init $@
	@make -C $@
