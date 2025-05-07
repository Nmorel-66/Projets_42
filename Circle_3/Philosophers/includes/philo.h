/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:30:00 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/07 11:36:55 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*****************************************************************************
 *  
 *  					PHILOSOPHERS Includes
 *  
 *****************************************************************************/

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/*****************************************************************************
 *  
 *  					PHILOSOPHERS Constants
 *  
 *****************************************************************************/

# define FAILURE 1
# define SUCCESS 0

/*****************************************************************************
 *  
 *  					PHILOSOPHERS Structure definitions
 *  
 *****************************************************************************/

struct	s_data;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long long			last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_data		*data;
	pthread_mutex_t		lock;
}				t_philo;

typedef struct s_data
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	int					all_ate; // compteur de philosophes ayant assez mangé
	int					someone_died;
	long long			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		state_mutex;

	t_philo				*philos;
}				t_data;

/*****************************************************************************
 *  
 *  					PHILOSOPHERS Function prototypes
 *  
 *****************************************************************************/

/* philo_init.c */
int			ft_init(t_data *data, int argc, char **argv);
int			ft_init_mutexes(t_data *data);
int			ft_init_philos(t_data *data);

/* philo_actions.c */
void		ft_print(t_philo *philo, char *msg);
void		ft_eat(t_philo *philo);
void		*ft_dining(void *arg);

/* philo_monitor.c */
int			all_philos_ate(t_data *data);
void		*ft_monitoring(void *arg);

/* philo_utils.c */
long long	ft_gettime(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_error_handler(char *message, int exit_code);
int			ft_strcmp(const char	*s1, const char	*s2);

#endif