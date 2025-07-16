/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:37:49 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/16 17:44:34 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	take_forks(t_philo *philo)
{
	t_data	*data;
	bool	alive;

	data = philo->data;
	pthread_mutex_lock(&philo->meal_mutex);
	alive = philo->alive;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (is_simulation_over(data) || !alive)
		return (false);
	pthread_mutex_lock(&philo->first_fork->mutex);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->second_fork->mutex);
	print_status(philo, "has taken a fork");
	return (true);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->eaten_mutex);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->eaten_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, "is eating");
	smart_sleep(data->time_to_eat);
	if (philo->meals_counter == data->must_eat)
	{
		print_status(philo, "\001\033[32m\002has eaten enough\001\033[0m\002");
		pthread_mutex_lock(&philo->meal_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->meal_mutex);
		if (all_philos_full(data))
		{
			pthread_mutex_lock(&data->end_simulation_mutex);
			data->end_simulation = true;
			pthread_mutex_unlock(&data->end_simulation_mutex);
		}
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->first_fork->mutex);
	pthread_mutex_unlock(&philo->second_fork->mutex);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}
