/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:00:56 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/07 02:00:56 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_data_philo	*t_data;
	int				index;

	t_data = malloc(sizeof(t_data_philo));
	if (!t_data)
		return (printf("t_data Error"), 0);
	t_data->args = argv;
	t_data->argc = argc;
	if (pthread_mutex_init(&t_data->write, NULL))
		return (printf("Mutex Error"), 0);
	if ((argc == 5 || argc == 6) && put_to_struct(t_data) != -1)
	{
		t_data->forks = malloc(sizeof(pthread_mutex_t) * t_data->philosophers);
		if (!t_data->forks)
			return (printf("Malloc Error"), 0);
		index = -1;
		while (++index < t_data->philosophers)
		{
			if ((pthread_mutex_init(&t_data->forks[index], NULL)))
				return (printf("Forks Mutex Error"), 0);
		}
		start_philo(t_data);
	}
	else
		write(2, "ERROR", 5);
}
