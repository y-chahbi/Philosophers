/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:38:27 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/03 01:43:41 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	puterror_exit(char *message)
{
	printf("%s\n", message);
	exit(1);
}

sem_t	*sem_create(char *name, unsigned int initilizer)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0644, initilizer);
	if (sem == SEM_FAILED)
		puterror_exit("Failed to create semaphore");
	return (sem);
}

void	ini(t_philos *philo, int i)
{
	philo[i].s_dead = sem_create("/sem/e", 1);
	philo[i].death = sem_create("/sem/o", 1);
	philo[i].write = sem_create("/sem/b", 1);
	philo[i].mealss = sem_create("/sem/c", 1);
	philo[i].time = sem_create("/sem/d", 1);
}
