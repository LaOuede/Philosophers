/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:25:04 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/24 19:43:29 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		write(fd, &str[i], 1);
}

int	ft_print_msg(t_philo *philo, char *msg)
{
	t_waiter	*waiter;
	time_t		timestamp;

	waiter = ft_get_waiter(NULL);
	pthread_mutex_lock(philo->mutex_print);
	if (waiter->all_alive == true)
	{
		if (philo->am_i_dead == false)
		{
			timestamp = ft_timestamp_in_ms(philo);
			printf("%ld %d %s\n", timestamp, philo->idx + 1, msg);
			pthread_mutex_unlock(philo->mutex_print);
			return (0);
		}
		waiter->all_alive = false;
		timestamp = ft_timestamp_in_ms(philo);
		printf("%ld %d %s\n", timestamp, philo->idx + 1, DIED);
		pthread_mutex_unlock(philo->mutex_print);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_print);
	return (1);
}
