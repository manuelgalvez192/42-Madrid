/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:52:12 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 17:55:02 by mgalvez-         ###   ########.fr       */
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

void	*simulation(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data  *data  = philo->data;

	while (true)
	{
		// 1) Si la simulación terminó globalmente o este filósofo ya está "full", salimos
		if (is_simulation_over(data) || philo->full)
			break;

		// 2) El ciclo normal de acciones
		think(philo);
		take_forks(philo);

		// 3) Antes de comer, compruebo otra vez si termina o si ya es full (por si hubo un cambio inmediato)
		if (is_simulation_over(data) || philo->full)
		{
			// Si en take_forks cogió tenedores pero justo ahora resultó que es full o terminó,
			// hay que liberarlos para no bloquear a los vecinos.
			release_forks(philo);
			break;
		}

		eat(philo);

		// 4) Si al comer se ha marcado full, libero forks y salgo
		if (philo->full || is_simulation_over(data))
		{
			release_forks(philo);
			break;
		}

		// 5) De lo contrario, sigue el flujo normal: soltar tenedores y dormir
		release_forks(philo);
		sleep_philo(philo);
	}

	return (NULL);
}


void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	if (data->must_eat == 0)
		return ;
	else if (data->num_of_philo == 1)
	{
		t_philo *philo = &data->philos[0];

		data->start_simulation = get_time();
		philo->last_meal_time = data->start_simulation;

		print_status(philo, "has taken a fork");
		smart_sleep(data->time_to_die);
		print_status(philo, "died");
		return;
	}
	else
	{
		data->start_simulation = get_time(); 
		i = -1;
		while (++i < data->num_of_philo)
			data->philos[i].last_meal_time = data->start_simulation;
		pthread_create(&monitor_thread, NULL, &monitor, data);
		i = -1;
		while (++i < data->num_of_philo)
			pthread_create(&data->philos[i].thread_id, NULL, &simulation, &data->philos[i]);
		i = -1;
		while (++i < data->num_of_philo)
			pthread_join(data->philos[i].thread_id, NULL);
		pthread_join(monitor_thread, NULL);
	}
}
