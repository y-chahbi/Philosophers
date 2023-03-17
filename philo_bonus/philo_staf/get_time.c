/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:01:22 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/13 14:22:28 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

long long	get_time(void)
{
	struct timeval	t0;

	gettimeofday(&t0, NULL);
	return (t0.tv_sec * 1000ll + t0.tv_usec / 1000ll);
}
