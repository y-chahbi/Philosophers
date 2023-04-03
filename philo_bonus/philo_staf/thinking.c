/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:33 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/02 18:01:27 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	thinking(t_philos *t_data, int id)
{
	sem_wait(t_data[t_data->id].write);
	printf("%lld %d is thinking\n",
		get_time() - t_data->start, id + 1);
	sem_post(t_data[t_data->id].write);
}
