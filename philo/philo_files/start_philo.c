/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:38 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/14 15:57:38 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

int	check_if_philo_die(t_philos *philos)
{
	int	all;

	if (my_while(philos) == 1)
		return (1);
	all = -1;
	if (philos->data->must_eat != -1)
	{
		while (++all < philos->data->philosophers)
		{
			pthread_mutex_lock(&philos[all].meals_mutex);
			if (philos[all].meals < philos->data->must_eat)
			{
				pthread_mutex_unlock(&philos[all].meals_mutex);
				return (0);
			}
			else
				return (1);
			pthread_mutex_unlock(&philos[all].meals_mutex);
		}
		return (1);
	}
	return (0);
}

void	mywhile(t_philos *philos)
{
	while (1)
	{
		pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
		eating(philos, "has taken a fork");
		pthread_mutex_lock(&philos->data->forks[philos->right_fork]);
		pthread_mutex_lock(&philos->meals_mutex);
		philos->meals++;
		pthread_mutex_unlock(&philos->meals_mutex);
		eating(philos, "has taken a fork");
		eating(philos, "is eating");
		pthread_mutex_lock(&philos->last_meal_mutex);
		philos->last_meal = get_time();
		pthread_mutex_unlock(&philos->last_meal_mutex);
		ft_usleep(philos->data->eat);
		pthread_mutex_unlock(&philos->data->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->data->forks[philos->right_fork]);
		sleeping(philos);
		thinking(philos);
	}
}

void	*routine(void *ptr)
{
	t_philos	*philos;

	philos = ptr;
	philos->left_fork = philos->id;
	philos->right_fork = (philos->id + 1) % philos->data->philosophers;
	if (philos->id % 2 != 0)
		usleep(500);
	mywhile(philos);
	return (NULL);
}

int	initialization(t_philos *philos, int i)
{
	if (pthread_mutex_init(&philos[i].last_meal_mutex, NULL))
		return (printf("Initialization Error"), 1);
	if (pthread_mutex_init(&philos[i].meals_mutex, NULL))
		return (printf("Initialization Error"), 1);
	if (pthread_create(&philos[i].philo, NULL, routine, &philos[i]))
		return (printf("pthread_create Error"), 1);
	if (pthread_detach(philos[i].philo))
		return (printf("pthread_detach Error"), 1);
	return (0);
}

void	start_philo(t_data_philo *t_data)
{
	int				i;
	t_philos		*philos;

	i = 0;
	philos = malloc(sizeof(t_philos) * t_data->philosophers);
	if (!philos)
	{
		printf("philos allocation error");
		return ;
	}
	while (t_data->philosophers > i)
	{
		philos[i].id = i;
		philos[i].meals = 0;
		philos[i].last_meal = get_time();
		philos[i].data = t_data;
		if (initialization(philos, i) != 0)
			return ;
		i++;
	}
	i = 0;
	while (check_if_philo_die(philos) != 1)
		i++;
}
