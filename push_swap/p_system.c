/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_system.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:49:29 by string            #+#    #+#             */
/*   Updated: 2023/09/21 15:12:48 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_init(t_node **a_stack, t_node **b_stack, t_node **a_nilnode,
		t_node **b_secondnode)
{
	if ((*b_stack)->num == NIL)
		exit(0);
	*a_nilnode = (*a_stack)->prev;
	*b_secondnode = (*b_stack)->next;
}

void	pa(t_node **a_stack, t_node **b_stack)
{
	t_node	*a_nilnode;
	t_node	*b_nilnode;
	t_node	*b_secondnode;

	pa_init(a_stack, b_stack, &a_nilnode, &b_secondnode);
	if (b_secondnode->num == NIL)
	{
		b_secondnode->prev = NULL;
		b_secondnode->next = NULL;
	}
	else
	{
		b_nilnode = (*b_stack)->prev;
		b_nilnode->next = b_secondnode;
		b_secondnode->prev = b_nilnode;
	}
	(*a_stack)->prev = (*b_stack);
	(*b_stack)->prev = a_nilnode;
	(*b_stack)->next = (*a_stack);
	a_nilnode->next = (*b_stack);
	(*a_stack) = (*b_stack);
	(*b_stack) = b_secondnode;
	write(1, "pa\n", 3);
}

void	pb_non_b_stack_case(t_node **a_stack, t_node **b_stack,
		t_node **b_nilnode)
{
	*b_nilnode = *b_stack;
	(*a_stack)->prev = *b_nilnode;
	(*a_stack)->next = *b_nilnode;
	(*b_nilnode)->prev = *a_stack;
	(*b_nilnode)->next = *a_stack;
}

void	pb(t_node **a_stack, t_node **b_stack)
{
	t_node	*a_nilnode;
	t_node	*b_nilnode;
	t_node	*a_secondnode;

	a_nilnode = (*a_stack)->prev;
	a_secondnode = (*a_stack)->next;
	a_secondnode->prev = a_nilnode;
	if ((*b_stack)->num == NIL)
		pb_non_b_stack_case(a_stack, b_stack, &b_nilnode);
	else
	{
		b_nilnode = (*b_stack)->prev;
		(*a_stack)->prev = b_nilnode;
		(*a_stack)->next = *b_stack;
		b_nilnode->next = (*a_stack);
		(*b_stack)->prev = (*a_stack);
	}
	a_nilnode->next = a_secondnode;
	*b_stack = *a_stack;
	*a_stack = a_secondnode;
	write(1, "pb\n", 3);
}
