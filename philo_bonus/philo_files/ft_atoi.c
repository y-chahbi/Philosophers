/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:01:25 by ychahbi           #+#    #+#             */
/*   Updated: 2023/03/10 15:47:34 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philosophers.h"

int	ft_atoi(char *str)
{
	int	dex;
	int	sign;
	int	rslt;

	dex = 0;
	sign = 1;
	rslt = 0;
	while ((str[dex] >= 9 && str[dex] <= 13)
		|| str[dex] == 32)
		dex++;
	if (str[dex] == '-' || str[dex] == '+')
	{
		if (str[dex++] == '-')
			sign = sign * -1;
	}
	while (str[dex] != '\0')
	{
		if (ft_isdigit(str[dex]) != 1)
			return (-1);
		rslt = (rslt * 10) + (str[dex++] - 48);
	}
	if (rslt > 2147483647 || rslt * sign < -2147483648)
		return (-1);
	return (rslt * sign);
}
