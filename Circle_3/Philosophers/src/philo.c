/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:29:06 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/11 21:19:35 by nimorel          ###   ########.fr       */
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

static void	ft_destroy_all_threads(t_data *data)
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

static int	ft_arg_checker(int ac, char **av)
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
	t_data		data;
	pthread_t	monitor;
	int			i;

	i = -1;
	if (ft_arg_checker(argc, argv) == FAILURE)
		return (ft_error_handler("Error : arguments", FAILURE));
	if (ft_atoi(argv[1]) == 1)
	return (printf("0 1 has taken a fork\n"), usleep(ft_atoi(argv[2]) * 1000),
				printf("\033[1;31m%s 1 💀 died\n\033[0m", argv[2]), SUCCESS);
	if (ft_init(&data, argc, argv))
		return (ft_error_handler("Error: init data failure", FAILURE));
	while (++i < data.nb_philos)
	{
		if (pthread_create(&data.philos[i].thread, NULL, &ft_dining,
				&data.philos[i]))
			return (ft_error_handler("Error : Philosopher thread failure", 1));
		usleep(50);
	}
	if (pthread_create(&monitor, NULL, &ft_monitoring, &data))
		return (ft_error_handler("Error: Monitor thread failure", 1));
	pthread_join(monitor, NULL);
	ft_join_threads(&data);
	ft_destroy_all_threads(&data);
	return (SUCCESS);
}
