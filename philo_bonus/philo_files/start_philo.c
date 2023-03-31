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

void	*routine(void *y)
{
	t_philos	*td;
	sem_t		forkt;

	td = y;
	while (td->data->is_dead != 1)
	{
		if ((get_time() - td->last_meal) > td->data->die)
		{
			td->data->is_dead = 1;
			sem_wait(&forkt);
			printf("%lld %d is die\n",
				get_time() - td->start,
				td->id + 1);
			ft_exit();
		}
		if (td->data->must_eat != -1 && td->meals == td->data->must_eat)
			ft_exit();
	}
	return (NULL);
}

void	start_philo(t_data_philo *t_data)
{
	int			i;
	sem_t		*forks;
	t_philos	*philo;

	sem_unlink("/sem");
	philo = malloc(sizeof(t_philos) * t_data->philosophers);
	forks = sem_open("/sem", O_CREAT, 0644, t_data->philosophers);
	i = 0;
	while (i < t_data->philosophers)
	{
		if (fork() == 0)
		{
			philo[i].start = get_time();
			philo[i].last_meal = get_time();
			philo[i].meals = 0;
			philo[i].id = i + 1;
			philo[i].data = t_data;
			pthread_create(&philo[i].philo, NULL, routine, &philo[i]);
			pthread_detach(philo[i].philo);
			while (t_data->is_dead != 1)
			{
				philo[i].meals++;
				sem_wait(forks);
				eating(&philo[i], "has taken the forks", i);
				sem_wait(forks);
				eating(&philo[i], "has taken the forks", i);
				eating(&philo[i], "is eating", i);
				philo[i].last_meal = get_time();
				sem_post(forks);
				sem_post(forks);
				ft_usleep(t_data->eat);
				sleeping(&philo[i], i);
				thinking(&philo[i], i);

			}
			ft_exit();
		}
		i++;
	}
	while (wait(0) != -1)
		;
}
