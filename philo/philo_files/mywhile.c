/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mywhile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:20:11 by ychahbi           #+#    #+#             */
/*   Updated: 2023/06/21 00:04:27 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

int	my_while(t_philos *philos)
{
	int	all;

	all = 0;
	while (all < philos->data->philosophers)
	{
		pthread_mutex_lock(&philos[all].meals_mutex);
		pthread_mutex_lock(&philos[all].last_meal_mutex);
		if (get_time() - philos[all].last_meal > philos->data->die)
		{
			pthread_mutex_lock(&philos->data->write);
			printf("%lld %d died\n",
				get_time() - philos->data->start,
				all + 1);
			return (1);
		}
		pthread_mutex_unlock(&philos[all].last_meal_mutex);
		pthread_mutex_unlock(&philos[all].meals_mutex);
		all++;
	}
	return (0);
}
