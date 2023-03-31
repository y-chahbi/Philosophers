/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:33 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/29 23:13:11 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	thinking(t_philos *t_data, int id)
{
	printf("%lld %d is thinking\n",
		get_time() - t_data->start, id + 1);
}
