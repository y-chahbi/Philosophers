/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:36 by ychahbi           #+#    #+#             */
/*   Updated: 2023/07/02 15:04:00 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	sleeping(t_philos *t_data, int id)
{
	sem_wait(t_data->data->write);
	printf("%lld %d is sleeping\n",
		get_time() - (*t_data).data->start,
		id + 1);
	sem_post(t_data->data->write);
	ft_usleep(t_data, t_data->data->sleep, id);
}
