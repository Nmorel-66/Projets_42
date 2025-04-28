/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 07:44:42 by nimorel           #+#    #+#             */
/*   Updated: 2025/04/26 09:36:21 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philos_ate(t_data *data)
{
	int	i;

	if (data->must_eat == -1)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].lock);
		if (data->philos[i].meals_eaten < data->must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].lock);
			return (0);
		}
		pthread_mutex_unlock(&data->philos[i].lock);
		i++;
	}
	return (FAILURE);
}

void	*ft_monitoring(void *arg)
{
	t_data	*data = (t_data *)arg;
	int		i;
	long long	now;

	while (1)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			now = ft_gettime();
			if ((now - data->philos[i].last_meal) > data->time_to_die)
			{
				pthread_mutex_lock(&data->state_mutex);
				data->someone_died = 1;
				pthread_mutex_lock(&data->write_mutex);
				printf("\033[1;31m%lld %d 💀 died\n\033[0m",
					now - data->start_time, data->philos[i].id);
				pthread_mutex_unlock(&data->write_mutex);
				pthread_mutex_unlock(&data->state_mutex);
				pthread_mutex_unlock(&data->philos[i].lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[i].lock);
			i++;
		}
		if (all_philos_ate(data))
		{
			pthread_mutex_lock(&data->state_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->state_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
