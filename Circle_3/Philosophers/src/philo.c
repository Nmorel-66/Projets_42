/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:29:06 by nimorel           #+#    #+#             */
/*   Updated: 2025/04/26 09:39:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (SUCCESS);
}

static void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->state_mutex);
	free(data->forks);
	free(data->philos);
}
static int ft_arg_checker(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (FAILURE);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_t	monitor;
	int		i;

	i = 0;
	if (ft_arg_checker(argc, argv) == FAILURE)
		return(ft_error_handler("Error : arguments", FAILURE));
	if (ft_init(&data, argc, argv))
		return (ft_error_handler("Error: init_data failure", FAILURE));
	while (i < data.nb_philos)
	{
		if (pthread_create(&data.philos[i].thread, NULL, &ft_dining,
			&data.philos[i]))
			return (ft_error_handler("Error : Philosopher thread failure", 1));
		usleep(50);
		i++;
	}
	if (pthread_create(&monitor, NULL, &ft_monitoring, &data))
		return (ft_error_handler("Error: Monitor thread failure", 1));
	pthread_join(monitor, NULL);
	ft_join_threads(&data);
	ft_destroy(&data);
	return (SUCCESS);
}
