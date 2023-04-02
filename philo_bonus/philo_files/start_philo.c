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
			sem_wait(td->data->death);
			sem_post(td->data->write);
			printf("%lld %d is die\n",
				get_time() - td->start,
				td->id + 1);
			sem_post(td->data->write);
			ft_exit();
		}
		if (td->data->must_eat != -1 && td->meals == td->data->must_eat)
		{
			sem_wait(td->data->death);
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
		sem_wait(t_data->meals);
		philo[i].meals++;
		sem_post(t_data->meals);
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

	sem_unlink("/sem/o");
	sem_unlink("/sem/b");
	sem_unlink("/sem/c");
	sem_unlink("/sem/d");
	sem_unlink("/sem/e");
	sem_unlink("/sem");
	philo = malloc(sizeof(t_philos) * t_data->philosophers);
	forks = sem_open("/sem", O_CREAT, 0644, t_data->philosophers);
	t_data->death = sem_open("/sem/o", O_CREAT, 0644, 1);
	t_data->write = sem_open("/sem/b", O_CREAT, 0644, 1);
	t_data->meals = sem_open("/sem/c", O_CREAT, 0644, 1);
	philo->time = sem_open("/sem/d", O_CREAT, 0644, 1);
	t_data->s_dead = sem_open("/sem/e", O_CREAT, 0644, 1);
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
			ptd_create(t_data, forks, philo, i);
			ft_exit();
		}
		i++;
	}
	while (wait(0) != -1)
		;
}
