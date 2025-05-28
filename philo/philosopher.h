/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:58:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/03/04 12:30:56 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_data
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	long	start_simulation;
	bool	end_simulation;
	t_philo	*philos;
	t_fork	*forks;
}	t_data;

void fill_data(const char **argv, t_data *data);

/* --- safe_functions --- */
void	*safe_calloc(size_t bytes);

/* --- parse --- */
void	check_valid_input(t_data *data, const char **argv);


/* --- set_up_simulation --- */


#endif