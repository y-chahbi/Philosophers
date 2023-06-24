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
	sem_t			*write;
	sem_t			*death;
	sem_t			*time;
	long long		start;
	int				is_dead;
}	t_data_philo;

typedef struct s_mut_philo
{
	int				id;
	int				meals;
	long long		last_meal;
	sem_t			*mealss;
	sem_t			*s_dead;
	sem_t			*lmeal;
	pthread_t		philo;
	pid_t			pids;
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
void		puterror_exit(char *message);
sem_t		*sem_create(char *name, unsigned int initilizer);
void		ini(t_philos *philo, int i);
void		ft_kill_all(t_philos *philo, pid_t pid, int n);
void		ft_wait_all(t_philos *philo, pid_t pid, int n);
void		waitandkill(t_philos *philo, t_data_philo *t_data);
#endif