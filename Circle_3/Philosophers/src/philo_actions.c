/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:32:15 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/07 13:37:14 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->data->state_mutex);
	if (!philo->data->someone_died)
	{
		timestamp = ft_gettime() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->write_mutex);
		if (ft_strcmp(msg, "\033[1;32m \xF0\x9F\x8D\x9D is eating\033[0m") == 0)
			printf("%lld %d %s %d meals eaten\n",
				timestamp, philo->id, msg, philo->meals_eaten + 1);
		else
			printf("%lld %d %s\n", timestamp, philo->id, msg);
		pthread_mutex_unlock(&philo->data->write_mutex);
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken left fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken right fork");
	ft_print(philo, "\033[1;32m \xF0\x9F\x8D\x9D is eating\033[0m");
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = ft_gettime();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*ft_dining(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->data->state_mutex);
		if (philo->data->someone_died)
		{
			pthread_mutex_unlock(&philo->data->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->state_mutex);
		ft_eat(philo);
		if (philo->data->must_eat != -1
			&& philo->meals_eaten >= philo->data->must_eat)
			break ;
		ft_print(philo, "\033[1;34m \xF0\x9F\x98\xB4 is sleeping\033[0m");
		usleep(philo->data->time_to_sleep * 1000);
		ft_print(philo, "\033[1;33m \xF0\x9F\xA4\x94 is thinking\033[0m");
	}
	return (NULL);
}
