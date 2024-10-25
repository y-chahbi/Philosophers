/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:42:56 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/13 14:33:09 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	ft_usleep(long long var)
{
	long long	time;

	time = get_time();
	while (get_time() - time < var)
		usleep(100);
}
