/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:33 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/01 14:43:55 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	thinking(t_philos *t_data, int id)
{
	sem_wait(t_data->data->write);
	printf("%lld %d is thinking\n",
		get_time() - t_data->start, id + 1);
	sem_post(t_data->data->write);
}
