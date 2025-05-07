/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:07:01 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/07 15:22:47 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (FAILURE);
		i++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (FAILURE);
	if (pthread_mutex_init(&data->state_mutex, NULL))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_init_philos(t_data *data)
{
	int		i;
	t_philo	*ph;

	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philos)
	{
		ph = &data->philos[i];
		ph->id = i + 1;
		ph->meals_eaten = 0;
		ph->last_meal = data->start_time;
		ph->left_fork = &data->forks[i];
		ph->right_fork = &data->forks[(i + 1) % data->nb_philos];
		ph->data = data;
		if (pthread_mutex_init(&ph->lock, NULL))
			return (1);
		i++;
	}
	return (SUCCESS);
}

int	ft_init(t_data *data, int argc, char **argv)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	data->all_ate = 0;
	data->someone_died = 0;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	data->start_time = ft_gettime();
	if (ft_init_mutexes(data))
		return (1);
	if (ft_init_philos(data))
		return (1);
	return (SUCCESS);
}
