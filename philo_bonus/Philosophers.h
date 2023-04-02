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
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include <pthread.h>

typedef struct t_philo
{
	char			**args;
	int				argc;	
	int				philosophers;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				is_dead;
	sem_t			*death;
	sem_t			*write;
	sem_t			*meals;
	sem_t			*s_dead;
}	t_data_philo;

typedef struct s_mut_philo
{
	long long		start;
	int				id;
	int				meals;
	long long		last_meal;
	pthread_t		philo;
	sem_t			*time;
	t_data_philo	*data;
}	t_philos;

int			put_to_struct(t_data_philo *t_data);
void		start_philo(t_data_philo *t_data);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
void		eating(t_philos *t_data, char *str, int id);
void		sleeping(t_philos *t_data, int id);
void		thinking(t_philos *t_data, int id);
long long	get_time(void);
void		ft_usleep(long long var);
void		ft_exit(void);
#endif