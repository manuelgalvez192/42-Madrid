/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:37:49 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 16:57:51 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_forks(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (is_simulation_over(data) || !philo->alive)
		return;
	pthread_mutex_lock(&philo->first_fork->mutex);
	print_status(philo, "has taken a fork");
	if (is_simulation_over(data) || !philo->alive)
	{
		pthread_mutex_unlock(&philo->first_fork->mutex);
		return;
	}
	pthread_mutex_lock(&philo->second_fork->mutex);
	print_status(philo, "has taken a fork");
}


void	eat(t_philo *philo)
{
    t_data *data = philo->data;

    // Primero incremento el contador de comidas
    philo->meals_counter++;

    // Actualizo inmediatamente last_meal_time antes de dormir
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->meal_mutex);

    // Imprimo estado y duermo el tiempo de comer
    print_status(philo, "is eating");
    smart_sleep(data->time_to_eat);

    // Luego, si alcanza must_eat, marco como lleno
    if (philo->meals_counter == data->must_eat)
    {
        print_status(philo, "has eaten enough");
        philo->full = true;
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
