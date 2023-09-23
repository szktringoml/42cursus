/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_a_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:52 by string            #+#    #+#             */
/*   Updated: 2023/09/21 15:12:06 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	printf("Error\n");
	exit(0);
}

void	inputcheck_incspace(int *n, char *argv)
{
	char	**nums;
	size_t	j;

	j = 0;
	nums = ft_split(argv, ' ');
	while (nums[j])
	{
		if (isnumsign_str(nums[j]) && INT_MIN <= ft_atoi(nums[j])
			&& ft_atoi(nums[j]) <= INT_MAX)
			*n = *n + 1;
		else
			error_print();
		j++;
		free(nums[j - 1]);
	}
	free(nums);
}

int	inputcheck_argcount(int argc, int n, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		error_print();
	while (i < argc)
	{
		if (isinc_space_str(argv[i]))
			inputcheck_incspace(&n, argv[i]);
		else
		{
			if (isnumsign_str(argv[i]) && INT_MIN <= ft_atoi(argv[i])
				&& ft_atoi(argv[i]) <= INT_MAX)
				n++;
			else
				error_print();
		}
		i++;
	}
	return (n);
}

void	storenode(int argc, char *argv[], t_node **a_stack)
{
	size_t	i;
	size_t	j;
	size_t	node_idx;
	char	**nums;

	i = 1;
	j = 0;
	node_idx = 0;
	while (i < argc)
	{
		if (isinc_space_str(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			while (nums[j])
			{
				ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(nums[j])));
				j++;
				free(nums[j - 1]);
			}
			free(nums);
		}
		else
			ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(argv[i])));
		i++;
	}
}

void	coordinate_compression(size_t n, t_node *a_stack)
{
	t_node	*search_node;
	size_t	small_cnt;
	size_t	search_idx;

	small_cnt = 0;
	while (a_stack->num != NIL)
	{
		search_idx = n - 1;
		search_node = a_stack->next;
		while (search_idx)
		{
			if (search_node->num == a_stack->num)
				error_print();
			if (search_node->num != NIL && a_stack->num > search_node->num)
				small_cnt++;
			if (search_node->num != NIL)
				search_idx--;
			search_node = search_node->next;
		}
		a_stack->coord_num = small_cnt;
		small_cnt = 0;
		a_stack = a_stack->next;
	}
}
