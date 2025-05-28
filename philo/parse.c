/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:26:41 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/05/28 20:26:41 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	check_valid_input(t_data *data, const char **argv)
{
	int argc;

	argc = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			ft_putstr_fd("Error: Arguments must be numeric.\n", 2);
			return (false);
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			ft_putstr_fd("Error: Arguments must be positive integers.\n", 2);
			return (false);
		}
		if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) > INT_MAX)
		{
			ft_putstr_fd("Error: Arguments must be within the range of int.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_counter = 0;
		data->philos[i].full = false;
		data->philos[i].second_fork = &data->forks[i];
		data->philos[i].first_fork = &data->forks[(i + 1) % data->num_of_philo];
		if (data->num_of_philo % 2 == 0)
		{
			data->philos[i].first_fork = &data->forks[i];
			data->philos[i].second_fork = &data->forks[(i + 1) % data->num_of_philo];
		}
		i++;
	}
}

bool	init_data(t_data *data, const char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = -1;
	data->num_of_philo = ft_atoi(argv[i++]);
	data->time_to_die = ft_atoi(argv[i++]);
	data->time_to_eat = ft_atoi(argv[i++]);
	data->time_to_sleep = ft_atoi(argv[i++]);
	if (argv[i])
		data->must_eat = ft_atoi(argv[i]);
	else
		data->must_eat = -1;
	data->start_simulation = 0;
	data->end_simulation = false;
	data->philos = ft_calloc(data->num_of_philo * sizeof(t_philo));
	data->forks = ft_calloc(data->num_of_philo * sizeof(t_fork));
	if (!data->philos || !data->forks)
		return (ft_putstr_fd("Error allocating memory.\n", 2),false);
	while (++a < data->num_of_philo)
	{
		data->forks[a].id = a;
		pthread_mutex_init(&data->forks[a].mutex, NULL);
	}
	init_philos(data);
}
