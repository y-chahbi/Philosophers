/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:01:22 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/07 02:01:22 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

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
		pthread_mutex_lock(&philos[philos->id].meals_mutex);
		philos->meals++;
		pthread_mutex_unlock(&philos[philos->id].meals_mutex);
		pthread_mutex_lock(&philos[philos->id].last_meal_mutex);
		philos->last_meal = get_time();
		pthread_mutex_unlock(&philos[philos->id].last_meal_mutex);
		ft_usleep(philos->data->eat);
		pthread_mutex_unlock(&philos->data->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->data->forks[philos->right_fork]);
		sleeping(philos);
		thinking(philos);
	}
	return (NULL);
}

void	four_args(t_data_philo *t_data)
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
		philos[i].is_dead = 0;
		philos[i].data = t_data;
		pthread_mutex_init(&philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&philos[i].meals_mutex, NULL);
		pthread_create(&philos[i].philo, NULL, routine, &philos[i]);
		i++;
	}
	i = 0;
	while (t_data->philosophers > i)
	{
		pthread_join(philos[i].philo, NULL);
		i++;
	}
}
