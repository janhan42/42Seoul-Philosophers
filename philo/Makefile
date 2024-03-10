# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 22:16:59 by janhan            #+#    #+#              #
#    Updated: 2024/03/02 08:14:53 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		philo
CC				=		cc

CFLAGS			=		-Wall -Wextra -Werror

SRCS_MAN		=	srcs/philo.c						\
					srcs/init/ft_fork_init.c			\
					srcs/init/ft_info_init.c			\
					srcs/init/ft_philo_init.c			\
					srcs/init/ft_time_init.c			\
					srcs/runutils/ft_check_died.c		\
					srcs/runutils/ft_check_finish_eat.c	\
					srcs/runutils/ft_eat.c				\
					srcs/runutils/ft_finish.c			\
					srcs/runutils/ft_routine.c			\
					srcs/runutils/ft_sleep.c			\
					srcs/runutils/ft_start.c			\
					srcs/runutils/ft_think.c			\
					srcs/utils/ft_atol.c				\
					srcs/utils/ft_current_time.c		\
					srcs/utils/ft_error.c				\
					srcs/utils/ft_free.c				\
					srcs/utils/ft_print.c				\
					srcs/utils/ft_strtol_sub.c			\
					srcs/utils/ft_strtol.c
OBJS_MAND		=	$(SRCS_MAN:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

$(NAME) : $(OBJS_MAND)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) -" $(NONE)
	@$(CC) $(CFLAGS) $(LIBFT_A) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - philo Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJS_MAND)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re
