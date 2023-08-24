#include "push_swap.h"

int inputcheck_argcount(int argc, int n, char *argv[])
{
	int i = 1;
	int j = 0; 
	char **nums;
	if(argc == 1)
	{
		printf("値が入力されていません");
		exit(0);
	}
	while(i < argc)
	{
		if(isinc_space_str(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			while(nums[j])
			{
				if(isnumsign_str(nums[j]) && 
					INT_MIN <= ft_atoi(nums[j]) && ft_atoi(nums[j]) <= INT_MAX)
					n++;
				else
				{
					printf("Error\n");
					exit(0);
				}
				j++;
			}
			free(nums);
		}
		else
		{
			if(isnumsign_str(argv[i]) && 
				INT_MIN <= ft_atoi(argv[i]) && ft_atoi(argv[i]) <= INT_MAX)
				n++;
			else
			{
				printf("Error\n");
				exit(0);
			}
		}
		i++;
	}
	return n;
}

s_node *ft_nodenew(long long num)
{
	s_node *new;
	new = malloc(sizeof(s_node));
	if(!new)
		exit(0);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	if(new->num == NIL)
		new->coord_num = NIL;
	return new;
}

s_node *ft_nodelast(s_node *a_stack)
{
	if(!a_stack)
			return NULL;
	while(a_stack->next->num != NIL)
		a_stack = a_stack->next;
	return a_stack;
}

void ft_nodeadd_back(s_node **stack, s_node *new)
{
	s_node *last;

	if((*stack)->num != NIL)
	{
		last = ft_nodelast(*stack);
		new->prev = last;
		new->next = last->next;
		last->next->prev = new;
		last->next = new;
		new->prev = last;
	}
	else
	{
		new->prev = *stack;
		new->next = *stack;
		(*stack)->prev = new;
		(*stack)->next = new;
		*stack = new;

	}
}
	
void storenode(int argc, char *argv[], s_node **a_stack)
{
	size_t i = 1;
	size_t j = 0;
	size_t node_idx = 0;
	char **nums;
	
	while(i < argc)
	{
		if(isinc_space_str(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			while(nums[j])
			{
				ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(nums[j])));
				j++;
			}
			free(nums);
		}
		else
			ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(argv[i])));
		i++;
	}
}

void coordinate_compression(size_t n, s_node *a_stack)
{
	s_node *search_node;
	size_t small_cnt;
	size_t search_idx;

	small_cnt = 0;
	while(a_stack->num != NIL)
	{
		search_idx = n-1;
		search_node = a_stack->next;
		while(search_idx)
		{
			if(search_node->num == a_stack->num)
			{
				printf("Error: 同じ値が引数に含まれる");
				exit(0);
			}

			//printf("search_node->num:%i\n", search_node->num);
			if(search_node->num != NIL && a_stack->num > search_node->num)
				small_cnt++;
			if(search_node->num != NIL)
				search_idx--;
			search_node = search_node->next;
		}
		
		a_stack->coord_num = small_cnt;
		printf("座標:%zu\n",small_cnt);
		small_cnt = 0;
		a_stack = a_stack->next;
		//printf("%zu番目の引数は%d番目に大きい\n", i, a_stack[i-1].coord_num);
	}
}

size_t ft_get_stacksize(s_node *stack)
{
	if(stack->num == NIL)
		return 0;
	size_t len;

	len = 0;
	while(stack->num != NIL)
	{
		//printf("%lli\n", stack->num);
		len++;
		stack = stack->next;
	}
	return len;
}

		

	
