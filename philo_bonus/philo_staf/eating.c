/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:39 by ychahbi           #+#    #+#             */
/*   Updated: 2023/07/03 16:35:25 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	ft_kill_all(void)
{
	kill(0, SIGINT);
}

void	ft_wait_all(t_philos *philo, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		kill(philo[i].pids, SIGKILL);
		i++;
	}
}

void	waitandkill(t_philos *philo, t_data_philo *t_data)
{
	pid_t		pid;
	int			status;

	pid = waitpid(-1, &status, 0);
	if (status == EXIT_SUCCESS)
		ft_wait_all(philo, t_data->philosophers);
	else
		ft_kill_all();
}

void	eating(t_philos *t_data, char *str, int id)
{
	sem_wait(t_data->data->write);
	printf("%lld %d %s\n",
		get_time() - (*t_data).data->start,
		id + 1, str);
	sem_post(t_data->data->write);
}
