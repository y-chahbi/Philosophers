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

	td = y;
	while (1)
	{
		if ((get_time() - td->last_meal) > td->data->die)
		{
			sem_wait(td->death);
			sem_post(td->write);
			printf("%lld %d is die\n",
				get_time() - td->start,
				td->id + 1);
			sem_post(td->write);
			ft_exit();
		}
		if (td->data->must_eat != -1 && td->meals == td->data->must_eat)
		{
			sem_wait(td->death);
			ft_exit();
		}
	}
	return (NULL);
}

void	ptd_create(t_data_philo *t_data, sem_t *forks, t_philos	*philo, int i)
{
	pthread_create(&philo[i].philo, NULL, routine, &philo[i]);
	pthread_detach(philo[i].philo);
	while (1)
	{
		sem_wait(philo[i].mealss);
		philo[i].meals++;
		sem_post(philo[i].mealss);
		sem_wait(forks);
		eating(&philo[i], "has taken the forks", i);
		sem_wait(forks);
		eating(&philo[i], "has taken the forks", i);
		eating(&philo[i], "is eating", i);
		sem_wait(philo->time);
		philo[i].last_meal = get_time();
		sem_post(philo->time);
		sem_post(forks);
		sem_post(forks);
		ft_usleep(t_data->eat);
		sleeping(&philo[i], i);
		thinking(&philo[i], i);
	}
}

void	start_philo(t_data_philo *t_data)
{
	int			i;
	sem_t		*forks;
	t_philos	*philo;

	forks = sem_create("/sem", t_data->philosophers);
	philo = malloc(sizeof(t_philos) * t_data->philosophers);
	if (philo == NULL)
		puterror_exit("Failed to allocate philo");
	i = -1;
	while (++i < t_data->philosophers)
	{
		if (fork() == 0)
		{
			philo[i].start = get_time();
			philo[i].last_meal = get_time();
			philo[i].meals = 0;
			philo[i].id = i + 1;
			philo[i].data = t_data;
			ini(philo, i);
			ptd_create(t_data, forks, philo, i);
			exit(0);
		}
	}
	while (wait(0) != -1)
		;
}
