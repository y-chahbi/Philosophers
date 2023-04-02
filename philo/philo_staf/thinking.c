/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:33 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/01 01:17:10 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	thinking(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lld %d is thinking\n",
		get_time() - philos->data->start, philos->id + 1);
	pthread_mutex_unlock(&philos->data->write);
}
