/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:57:15 by string            #+#    #+#             */
/*   Updated: 2023/09/21 15:15:20 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_value_operation(t_node **b_stack,
							size_t prev_dist_to_destination,
							size_t next_dist_to_destination)
{
	if (next_dist_to_destination < prev_dist_to_destination)
	{
		while (next_dist_to_destination--)
			rb(b_stack, 1);
	}
	else
	{
		while (prev_dist_to_destination--)
			rrb(b_stack, 1);
	}
}

void	search_value(t_node **b_stack, size_t search_value)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	t_node	*searchnode;

	searchnode = *b_stack;
	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	while (searchnode->coord_num != search_value)
	{
		searchnode = searchnode->prev;
		if (searchnode->coord_num != NIL)
			prev_dist_to_destination++;
	}
	searchnode = *b_stack;
	while (searchnode->coord_num != search_value)
	{
		searchnode = searchnode->next;
		next_dist_to_destination++;
	}
	search_value_operation(b_stack, prev_dist_to_destination,
		next_dist_to_destination);
}

void	search_rangevalue_operation(t_node **a_stack, t_node **b_stack,
		size_t search_range_max)
{
	size_t	next_dist_to_destination;
	t_node	*searchnode;

	searchnode = *a_stack;
	next_dist_to_destination = 0;
	while (searchnode->coord_num > search_range_max)
	{
		searchnode = searchnode->next;
		next_dist_to_destination++;
	}
	while (next_dist_to_destination--)
		ra(a_stack, 1);
}
