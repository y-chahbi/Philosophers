/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:39 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/30 15:07:07 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	eating(t_philos *t_data, char *str, int id)
{
	printf("%lld %d %s\n",
		get_time() - t_data->start,
		id + 1, str);
}
