/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:01:31 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/07 02:01:31 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

int	put_to_struct(t_data_philo *t_data)
{
	t_data->philosophers = ft_atoi(t_data->args[1]);
	t_data->die = ft_atoi(t_data->args[2]);
	t_data->eat = ft_atoi(t_data->args[3]);
	t_data->sleep = ft_atoi(t_data->args[4]);
	t_data->is_dead = 0;
	t_data->start = get_time();
	if (t_data->argc == 6)
		t_data->must_eat = ft_atoi(t_data->args[5]) + 1;
	else
		t_data->must_eat = -1;
	if (t_data->philosophers <= 0 || t_data->die <= 0 || t_data->eat <= 0
		|| t_data->sleep <= 0 || (t_data->argc == 6 && t_data->must_eat <= 0))
		return (write(2, "Args -> ", 8), -1);
	return (0);
}
