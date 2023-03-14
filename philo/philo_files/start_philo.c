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
	pthread_mutex_lock(&philos->meals_mutex);
	pthread_mutex_lock(&philos->last_meal_mutex);
	if (philos->last_meal / philos->meals > philos->data->die)
		philos->data->is_dead = 1;
	if (philos->data->is_dead == 1)
	{
		pthread_mutex_lock(&philos->data->write);
		printf("%lld %d is die\n",
			get_time() - philos->data->start,
			philos->id + 1);
		return (1);
	}
	if (philos->data->must_eat != -1 && philos->meals == philos->data->must_eat)
		return (1);
	pthread_mutex_unlock(&philos->last_meal_mutex);
	pthread_mutex_unlock(&philos->meals_mutex);
	return (0);
}

void	*routine(void *ptr)
{
	t_philos	*philos;

	philos = ptr;
	philos->left_fork = philos->id;
	philos->right_fork = (philos->id + 1) % philos->data->philosophers;
	if (philos->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
		eating(philos, "has taken a left fork");
		pthread_mutex_lock(&philos->data->forks[philos->right_fork]);
		eating(philos, "has taken a right fork");
		eating(philos, "is eating");
		pthread_mutex_lock(&philos->meals_mutex);
		philos->meals++;
		pthread_mutex_unlock(&philos->meals_mutex);
		pthread_mutex_lock(&philos->last_meal_mutex);
		philos->last_meal = get_time() - philos->data->start;
		pthread_mutex_unlock(&philos->last_meal_mutex);
		ft_usleep(philos->data->eat);
		pthread_mutex_unlock(&philos->data->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->data->forks[philos->right_fork]);
		sleeping(philos);
		thinking(philos);
	}
	return (NULL);
}

void	start_philo(t_data_philo *t_data)
{
	int				i;
	t_philos		*philos;

	i = 0;
	philos = malloc(sizeof(t_philos) * t_data->philosophers);
	while (t_data->philosophers > i)
	{
		philos[i].id = i;
		philos[i].meals = 0;
		philos[i].last_meal = t_data->start;
		philos[i].data = t_data;
		pthread_mutex_init(&philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&philos[i].meals_mutex, NULL);
		pthread_create(&philos[i].philo, NULL, routine, &philos[i]);
		pthread_detach(philos[i].philo);
		i++;
	}
	i = 0;
	while (check_if_philo_die(philos) != 1)
		i++;
}
