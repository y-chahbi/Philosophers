# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 02:01:03 by ychahbi           #+#    #+#              #
#    Updated: 2023/03/07 02:01:03 by ychahbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBJ = philo_bonus
SRC  = philo.c philo_files/put_to_struct.c philo_files/start_philo.c philo_files/ft_isdigit.c philo_files/ft_atoi.c philo_staf/eating.c  philo_staf/sleeping.c philo_staf/get_time.c philo_staf/thinking.c philo_staf/ft_usleep.c philo_files/handl.c philo_files/ft_exit.c
CC=cc
FLAGS=-Wall -Wextra -Werror #-fsanitize=thread -g
RM=rm -f
OBJ_ALL = $(SRC:.c=.o)

all: $(SUBJ)

$(SUBJ): $(OBJ_ALL)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c Philosophers.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_ALL) 


fclean: clean
	$(RM) $(SUBJ)

re: fclean all

.PHONY: clean fclean all re