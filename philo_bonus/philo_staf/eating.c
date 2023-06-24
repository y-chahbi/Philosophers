/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:03:39 by ychahbi           #+#    #+#             */
/*   Updated: 2023/06/20 10:00:13 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

void	ft_kill_all(t_philos *philo, pid_t pid, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		if (philo[i].pids != pid)
			kill(philo->pids, SIGKILL);
		i++;
	}
}

void	ft_wait_all(t_philos *philo, pid_t pid, int n)
{
	int	i;
	int	status;
	int	pids;

	i = 0;
	while (n > i)
	{
		if (philo[i].pids != pid)
			pids = waitpid(pid, &status, 0);
		i++;
	}
}

void	waitandkill(t_philos *philo, t_data_philo *t_data)
{
	pid_t		pid;
	int			status;

	pid = waitpid(-1, &status, 0);
	if (status == EXIT_SUCCESS)
		ft_wait_all(philo, pid, t_data->philosophers);
	else
		ft_kill_all(philo, pid, t_data->philosophers);
}

void	eating(t_philos *t_data, char *str, int id)
{
	sem_wait(t_data->data->write);
	printf("%lld %d %s\n",
		get_time() - (*t_data).data->start,
		id + 1, str);
	sem_post(t_data->data->write);
}
