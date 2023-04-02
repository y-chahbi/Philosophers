/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:39 by ychahbi           #+#    #+#             */
/*   Updated: 2023/04/01 14:43:05 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	eating(t_philos *t_data, char *str, int id)
{
	sem_wait(t_data->data->write);
	printf("%lld %d %s\n",
		get_time() - t_data->start,
		id + 1, str);
	sem_post(t_data->data->write);
}
