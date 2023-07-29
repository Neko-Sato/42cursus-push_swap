# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:24:52 by hshimizu          #+#    #+#              #
#    Updated: 2023/07/30 04:20:10 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
DIR				= .
FT_PRINTF		= $(DIR)/libftprintf
INCS_DIR		= $(DIR)/includes
OBJS_DIR		= $(DIR)/objs
MAIN			= $(DIR)/main.c

SRCS			= \
	$(addprefix $(DIR)/srcs/, \
		push_swap.c \
		stack.c \
		stackset.c \
		actions_p.c \
		actions_s.c \
		actions_r.c \
		actions_rr.c \
		sort_utils.c \
		sort_stack.c \
		mixed_sort.c \
		polar_sort.c \
		bisection_sort.c \
	) \
	$(addprefix $(DIR)/utils/, \
		ft_atoi.c \
		ft_isdigit.c \
	) \

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g
LDFLAGS			= -L$(FT_PRINTF)
IDFLAGS			= -I$(FT_PRINTF)
LIBS			= -lftprintf
IDFLAGS			+= -I$(INCS_DIR)

.PHONY: all clean fclean re bonus

all: $(FT_PRINTF) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT_PRINTF) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(SRCS) $(INCS_DIR)
	@norminette $^

.PHONY: $(FT_PRINTF)
$(FT_PRINTF):
	@make -C $@