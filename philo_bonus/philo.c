/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:00:56 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/07 02:00:56 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_data_philo	*t_data;

	t_data = malloc(sizeof(t_data_philo));
	t_data->args = argv;
	t_data->argc = argc;
	t_data->is_dead = 0;
	if ((argc == 5 || argc == 6) && put_to_struct(t_data) != -1)
		start_philo(t_data);
	else
		write(2, "ERROR", 5);
}
