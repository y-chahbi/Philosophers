/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:01:06 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/07 02:01:06 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_philo
{
	char			**args;
	int				argc;	
	int				philosophers;
	int				die;
	int				eat;
	int				sleep;
	long long		start;
	pthread_mutex_t	write;
	int				must_eat;
	pthread_mutex_t	*forks;
}	t_data_philo;

typedef struct s_mut_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals;
	pthread_mutex_t	meals_mutex;
	int				is_dead;
	long long		last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_t		philo;
	t_data_philo	*data;
}	t_philos;

int			put_to_struct(t_data_philo *t_data);
void		four_args(t_data_philo *t_data);
void		five_args(t_data_philo *t_data);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
void		eating(t_philos *philos, char *str);
void		sleeping(t_philos *philos);
void		thinking(t_philos *philos);
long long	get_time(void);
void		ft_usleep(long long var);
#endif