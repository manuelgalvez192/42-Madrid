/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:50:47 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/30 16:55:06 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int argc, const char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	fill_data(argv, &data);

	return (0);
}

void fill_data(const char **argv, t_data *data)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	int i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data->philo->id = i;
		i++;
	}

}
