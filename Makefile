# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:05:06 by hshimizu          #+#    #+#              #
#    Updated: 2025/10/16 04:12:44 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S				:= $(shell uname -s)

NAME 				:= push_swap
NAME_DEV 			:= $(NAME)_dev
NAME_BONUS			:= checker
NAME_BONUS_DEV		:= $(NAME_BONUS)_dev

SRCS				:= \
	main.c \
	atoi_array.c \
	compress_coords.c \
	stacks.c \
	stacks_getters.c \
	action_p.c \
	action_s.c \
	action_r.c \
	action_rr.c \
	push_swap.c

SRCS_BONUS			:= \
	main_bonus.c \
	atoi_array.c \
	stacks.c \
	stacks_getters.c \
	stacks_check.c \
	action_p.c \
	action_s.c \
	action_r.c \
	action_rr.c \
	checker.c

OUTDIR				:= .out
OBJS				:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))
OBJS_DEV			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.o))
DEPS				:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.d))
DEPS_DEV			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.d))
OBJS_BONUS			:= $(addprefix $(OUTDIR)/, $(SRCS_BONUS:.c=.o))
OBJS_BONUS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS_BONUS:.c=_dev.o))
DEPS_BONUS			:= $(addprefix $(OUTDIR)/, $(SRCS_BONUS:.c=.d))
DEPS_BONUS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS_BONUS:.c=_dev.d))

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS				+= -fno-builtin -fno-common
CFLAGS				+= -fPIC -MMD -MP
IDFLAGS				:= -I./libft -I./libftprintf
LDFLAGS				:= -L./libft -L./libftprintf
LIBS				:= -lft -lftprintf -Wl,-rpath,./libft -Wl,-rpath,./libftprintf
LIBS_DEV			:= -lft_dev -lftprintf_dev -Wl,-rpath,./libft -Wl,-rpath,./libftprintf

CFLAGS_OPT			:= -O3 -DNDEBUG
CFLAGS_DEV			:= -g -fsanitize=address
ifneq ($(shell $(CC) --version | grep -i clang),)
CFLAGS_DEV			+= -fstandalone-debug
endif

export LIBFT_PATH	:= $(CURDIR)/libft

.PHONY: all clean fclean re bonus libft libftprintf

all:
ifeq ($(UNAME_S),Linux)
	@$(MAKE) $(NAME) -j $(shell nproc)
else ifeq ($(UNAME_S),Darwin)
	@$(MAKE) $(NAME) -j $(shell sysctl -n hw.ncpu)
else
	@$(MAKE) $(NAME)
endif

bonus:
ifeq ($(UNAME_S),Linux)
	@$(MAKE) $(NAME_BONUS) -j $(shell nproc)
else ifeq ($(UNAME_S),Darwin)
	@$(MAKE) $(NAME_BONUS) -j $(shell sysctl -n hw.ncpu)
else
	@$(MAKE) $(NAME_BONUS)
endif

$(NAME): CFLAGS += $(CFLAGS_OPT)
$(NAME): $(OBJS) | libft libftprintf
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(NAME_BONUS): CFLAGS += $(CFLAGS_OPT)
$(NAME_BONUS): $(OBJS_BONUS) | libft libftprintf
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(NAME_DEV): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV): $(OBJS_DEV) | libft libftprintf
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(NAME_BONUS_DEV): CFLAGS += $(CFLAGS_DEV)
$(NAME_BONUS_DEV): $(OBJS_BONUS_DEV) | libft libftprintf
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OUTDIR)/%_dev.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

libft:
	@$(MAKE) -C $@

libftprintf: libft
	@$(MAKE) -C $@

clean:
	$(RM) -r $(OUTDIR)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C libftprintf fclean

fclean: clean
	$(RM) $(NAME) $(NAME_DEV) $(NAME_BONUS) $(NAME_BONUS_DEV)

re:
	@$(MAKE) fclean
	@$(MAKE)

-include $(DEPS) $(DEPS_DEV)
