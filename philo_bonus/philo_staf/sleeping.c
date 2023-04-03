/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:36 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/02 18:01:48 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	sleeping(t_philos *t_data, int id)
{
	sem_wait(t_data[t_data->id].write);
	printf("%lld %d is sleeping\n",
		get_time() - t_data->start,
		id + 1);
	sem_post(t_data[t_data->id].write);
	ft_usleep(t_data->data->sleep);
}
