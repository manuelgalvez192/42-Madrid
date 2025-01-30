/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:58:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/30 17:00:13 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

typedef struct s_data_philo
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	t_philosopher	*philo;
	int	*forks;
}	t_data_philo;

typedef struct s_philosopher
{
	int		id;
	bool	alive;
	bool	eating;
	bool	sleeping;
	bool	thinking;
	t_philosopher	*left;
}	t_philosopher;


/* --- set_up_simulation --- */
void	set_up_simulation(t_data_philo *data);


#endif