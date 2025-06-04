/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:52:12 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 19:10:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	all_philos_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (!data->philos[i].full)
			return (false);
		i++;
	}
	return (true);
}

bool	is_simulation_over(t_data *data)
{
	bool result;

	pthread_mutex_lock(&data->end_simulation_mutex);
	result = data->end_simulation;
	pthread_mutex_unlock(&data->end_simulation_mutex);
	return (result);
}

void *simulation(void *arg)
{
    t_philo *philo;
    t_data  *data;

	philo = (t_philo *)arg;
	data = philo->data;
    if (data->num_of_philo == 1)
    {
        pthread_mutex_lock(&philo->first_fork->mutex);
        print_status(philo, "has taken a fork");
        smart_sleep(data->time_to_die);
        pthread_mutex_unlock(&philo->first_fork->mutex);
        return (NULL);
    }
    while (!is_simulation_over(data) && !philo->full)
    {
        think(philo);
        take_forks(philo);
        if (!is_simulation_over(data))
            eat(philo);
        release_forks(philo);
        if (philo->full || is_simulation_over(data))
            break;
        sleep_philo(philo);
    }
    return (NULL);
}

void start_simulation(t_data *data)
{
    int         i;
    pthread_t   monitor_thread;

	if (data->must_eat == 0)
		return ;
    data->start_simulation = get_time();
    i = -1;
    while (++i < data->num_of_philo)
        data->philos[i].last_meal_time = data->start_simulation;
    pthread_create(&monitor_thread, NULL, &monitor, data);
    i = -1;
    while (++i < data->num_of_philo)
        pthread_create(&data->philos[i].thread_id, NULL, &simulation, 	&data->philos[i]);
    i = -1;
    while (++i < data->num_of_philo)
        pthread_join(data->philos[i].thread_id, NULL);
    pthread_join(monitor_thread, NULL);
}
