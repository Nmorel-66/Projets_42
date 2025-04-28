/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:30:00 by nimorel           #+#    #+#             */
/*   Updated: 2025/04/26 09:39:18 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*****************************************************************************
 *  
 *  					PHILOSOPHERS Includes
 *  
 *****************************************************************************/

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// forward declaration
struct s_data;

typedef struct s_philo
{
	int					id;             // numéro du philosophe (1 à n)
	int					meals_eaten;    // nombre de repas pris
	long long			last_meal;      // timestamp du dernier repas
	pthread_t			thread;         // thread du philosophe
	pthread_mutex_t		*left_fork;     // pointeur vers mutex de la fourchette gauche
	pthread_mutex_t		*right_fork;    // idem pour la droite
	struct s_data		*data;          // lien vers les données globales
	pthread_mutex_t		lock;           // mutex pour protéger ses propres données
}				t_philo;

typedef struct s_data
{
	int					nb_philos;      // nombre de philosophes
	int					time_to_die;    // temps avant qu’un philo ne meure sans manger
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;       // nombre de repas requis (optionnel)
	int					all_ate;        // compteur de philosophes ayant assez mangé
	int					someone_died;   // flag d’arrêt de simulation
	long long			start_time;     // timestamp du début de simulation
	pthread_mutex_t		*forks;         // tableau de mutex pour chaque fourchette
	pthread_mutex_t		write_mutex;    // mutex pour l'affichage/logs
	pthread_mutex_t		state_mutex;    // mutex pour les flags globaux (someone_died, all_ate)

	t_philo				*philos;        // tableau de philosophes
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

#endif