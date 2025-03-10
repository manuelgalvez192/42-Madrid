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

typedef struct s_philosopher
{
	int		id;
	bool	alive;
	bool	eating;
	bool	sleeping;
	bool	thinking;
	struct s_philosopher	*left;
}	t_philosopher;

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	t_philosopher	*philo;
	int	*forks;
}	t_data;

void fill_data(const char **argv, t_data *data);

/* --- set_up_simulation --- */


#endif