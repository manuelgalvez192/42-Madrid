/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:58:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 19:11:00 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct s_data t_data;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_counter;
	bool			full;
	bool			alive;
	long			last_meal_time;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_simulation;
	bool			end_simulation;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	end_simulation_mutex;
	pthread_mutex_t	print_mutex;
}	t_data;

/* --- parse --- */
bool	is_numeric(const char *str);
bool	check_valid_input(const char **argv);
void	init_philos(t_data *data);
void	assign_data(t_data *data, const char **argv, int i);
bool	init_data(t_data *data, const char **argv);

/* --- philo_tasks --- */
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	release_forks(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);

/* --- philo_controller --- */
void	print_status(t_philo *philo, const char *msg);
long	get_time(void);
void	smart_sleep(long sleep_time);
void	die_check(t_data *data, int i, long time_since_last);
void	*monitor(void *arg);

/* --- start_simulation --- */
bool	all_philos_full(t_data *data);
bool	is_simulation_over(t_data *data);
void	*simulation(void *arg);
void	start_simulation(t_data *data);

/* --- cleaner --- */
void	cleanup(t_data *data);

#endif
