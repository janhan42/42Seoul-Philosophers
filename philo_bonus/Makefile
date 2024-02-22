NAME			=		philo_bonus
CC				=		cc

CFLAGS			=		-Wall -Wextra -Werror


SRCS_MAN		=	srcs/philo_bonus.c								\
					srcs/init/ft_philo_init_bonus.c				\
					srcs/init/ft_print_bonus.c					\
					srcs/init/ft_sem_init_bonus.c				\
					srcs/init/ft_time_init_bonus.c				\
					srcs/runutils/ft_eat_bonus.c				\
					srcs/runutils/ft_sleep_bonus.c				\
					srcs/runutils/ft_think_bonus.c				\
					srcs/runutils/ft_child_routine_bonus.c			\
					srcs/utils/ft_atol_bonus.c					\
					srcs/utils/ft_current_time_bonus.c			\
					srcs/utils/ft_error_bonus.c					\
					srcs/utils/ft_ltoa_bonus.c					\
					srcs/utils/ft_strtol_bonus.c				\
					srcs/utils/ft_strtol_sub_bonus.c
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
