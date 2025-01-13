/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:48 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/13 02:46:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_data {
	t_node	*a;
	int		len_a;
	t_node	*b;
	int		len_b;
	char	**split;
}	t_data;

/* --- swap functions --- */
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_ss(t_data *data);

/* --- push functions --- */
void	push_b(t_data *data);
void	push_a(t_data *data);

/* --- rotate functions --- */
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_rr(t_data *data);

/* --- reverse rotate functions --- */
void	rev_rotate_a(t_data *data);
void	rev_rotate_b(t_data *data);
void	rev_rotate_rrr(t_data *data);

/* --- parse --- */
void	parse_str(char	*str, t_data *data);
void	parse_args(char *str, t_data *data, int i);

/* --- checker --- */
void	call_check_fill(t_data *data);
void	check_digits(t_data *data);
void	check_repeated(t_data *data);

/* --- ft_utils --- */
int		ft_ps_atoi(const char *str, t_data *data);
int		ft_split_len(char **split);

/* --- math_utils --- */
double	ft_sqrt(int n);
int		calc_k(t_data *data);

/* --- list_utils --- */
void	fill_node(t_data *data);
void	add_to_list(t_data *data, int value);
void	calculate_index(t_data *data);
void	calculate_length(t_data *data);
int		get_min(t_node *a);

/* --- algorithm --- */
void	start_algo(t_data *data);
void	k_sort(t_data *data);
void	move_highest_to_top(t_data *data);
bool	is_sorted(t_data *data);

/* --- sort --- */
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);

/* --- error --- */
void	error(t_data *data);
void	free_split(char **split);

void print_stack_with_indices(t_node *stack);

#endif
