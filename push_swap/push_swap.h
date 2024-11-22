/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:48 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/18 15:36:27 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*a;
	t_node	*b;
}	t_stack;

/* --- swap functions --- */
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ss(t_stack *stack);

/* --- push functions --- */
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

/* --- rotate functions --- */
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_rr(t_stack *stack);

/* --- reverse rotate functions --- */
void	rev_rotate_a(t_stack *stack);

/* --- parse --- */
void	parse(char	*str);

/* --- error --- */
void	error(void);


#endif
