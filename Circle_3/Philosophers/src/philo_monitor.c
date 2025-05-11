/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 07:44:42 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/11 21:18:23 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_ate(t_data *data)
{
	int	i;

	if (data->must_eat == -1)
		return (SUCCESS);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].lock);
		if (data->philos[i].meals_eaten < data->must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].lock);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&data->philos[i].lock);
		i++;
	}
	return (FAILURE);
}

static int	ft_is_someone_die(t_data *data, int *i)
{
	long long	now;

	now = ft_gettime();
	if ((now - data->philos[*i].last_meal) >= data->time_to_die)
	{
		pthread_mutex_lock(&data->state_mutex);
		data->someone_died = 1;
		pthread_mutex_lock(&data->write_mutex);
		printf("\033[1;31m%lld %d 💀 died\n\033[0m",
			now - data->start_time, data->philos[*i].id);
		pthread_mutex_unlock(&data->write_mutex);
		pthread_mutex_unlock(&data->state_mutex);
		pthread_mutex_unlock(&data->philos[*i].lock);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	*ft_monitoring(void *arg)
{
	t_data		*data;
	int			i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			if (ft_is_someone_die(data, &i))
				return (NULL);
			pthread_mutex_unlock(&data->philos[i].lock);
			i++;
		}
		if (ft_all_ate(data))
		{
			pthread_mutex_lock(&data->state_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->state_mutex);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
