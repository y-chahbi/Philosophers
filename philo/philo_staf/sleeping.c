/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:36 by ychahbi           #+#    #+#             */
/*   Updated: 2023/05/09 15:21:04 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	sleeping(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lld %d is sleeping\n",
		get_time() - philos->data->start,
		philos->id + 1);
	pthread_mutex_unlock(&philos->data->write);
	ft_usleep(philos->data->sleep);
}
