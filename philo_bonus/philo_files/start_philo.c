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

void	ptd_create(t_data_philo *t_data, sem_t *forks, t_philos	*philo, int i)
{
	while (1)
	{
		sem_wait(forks);
		eating(philo, "has taken the forks", i);
		sem_wait(forks);
		eating(philo, "has taken the forks", i);
		eating(philo, "is eating", i);
		sem_wait(philo[i].mealss);
		philo[i].meals++;
		sem_post(philo[i].mealss);
		ft_usleep(philo, t_data->eat, i);
		sem_wait(philo[i].lmeal);
		philo[i].last_meal = get_time();
		sem_post(philo[i].lmeal);
		sem_post(forks);
		sem_post(forks);
		sleeping(philo, i);
		thinking(philo, i);
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
		philo[i].last_meal = get_time();
		philo[i].meals = 0;
		philo[i].id = i + 1;
		philo[i].data = t_data;
		ini(philo, i);
		philo[i].pids = fork();
		if (philo[i].pids == 0)
		{
			ptd_create(t_data, forks, philo, i);
			exit(1);
		}
	}
	waitandkill(philo, t_data);
}
