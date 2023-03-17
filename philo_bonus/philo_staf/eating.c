/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:39 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/13 14:36:51 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	eating(t_philos *philos, char *str)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lld %d %s\n",
		get_time() - philos->data->start,
		philos->id + 1, str);
	pthread_mutex_unlock(&philos->data->write);
}
