/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:42:56 by ychahbi           #+#    #+#             */
/*   Updated: 2023/07/03 17:05:53 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	ft_usleep(t_philos *philo, long long var, int i)
{
	long long	time;

	time = get_time();
	while (get_time() - time < var)
	{
		if (get_time() - philo[i].last_meal >= philo->data->die)
		{
			sem_wait(philo->data->write);
			printf("%lld %d is die\n",
				get_time() - philo->data->start,
				philo[i].id);
			exit(EXIT_FAILURE);
		}
		if (philo->data->must_eat != -1
			&& philo[i].meals > philo->data->must_eat + 1)
		{
			sem_wait(philo->data->write);
			exit(EXIT_SUCCESS);
		}
		usleep(100);
	}
}
