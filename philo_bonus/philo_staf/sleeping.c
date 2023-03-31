/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:36 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/29 23:13:28 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	sleeping(t_philos *t_data, int id)
{
	printf("%lld %d is sleeping\n",
		get_time() - t_data->start,
		id + 1);
	ft_usleep(t_data->data->sleep);
}