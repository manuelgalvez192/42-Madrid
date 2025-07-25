/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:58:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/16 17:57:03 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_data	t_data;

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
	pthread_mutex_t	eaten_mutex;
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
bool	check_valid_input(const char **argv);
void	init_philos(t_data *data);
bool	assign_data(t_data *data, const char **argv, int i);
void	initialize(t_data *data, int i);
bool	init_data(t_data *data, const char **argv);

/* --- philo_tasks --- */
bool	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	release_forks(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);

/* --- philo_controller --- */
void	print_status(t_philo *philo, const char *msg);
long	ft_get_time(void);
void	smart_sleep(long sleep_time);
bool	die_check(t_data *data, int i, long time_since_last);
void	*monitor(void *arg);

/* --- start_simulation --- */
bool	all_philos_full(t_data *data);
bool	is_simulation_over(t_data *data);
void	*simulation(void *arg);
void	*one_philo_case(t_philo *philo, t_data *data);
void	start_simulation(t_data *data);

/* --- cleaner --- */
void	cleanup(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);

/* --- utils --- */
bool	is_philo_dead_or_full(t_data *data, int i);
bool	is_numeric(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);

#endif
