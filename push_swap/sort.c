#include "inc/push_swap.h"
void sort_three_or_less(size_t n, s_node **stack)
{
	s_node *first;
	s_node *second;
	s_node *third;
	if(n == 2)
		sa(stack, 1);
	if(n == 3)
	{	
		first = *stack;
		second = first->next;
		third = second->next;
		if(first->coord_num < third->coord_num  && third->coord_num < second->coord_num)
		{
			rra(stack, 1);
			sa(stack, 1);
		}
		if(third->coord_num < second->coord_num && second->coord_num < first->coord_num)
		{
			sa(stack, 1);
			rra(stack, 1);	
		}
		if(second->coord_num < third->coord_num && third->coord_num < first->coord_num)
			ra(stack, 1);
		if(third->coord_num < first->coord_num && first->coord_num < second->coord_num)
			rra(stack, 1);
		if(second->coord_num < first->coord_num && first->coord_num < third->coord_num)
			sa(stack, 1);
	}
}

		
void search_value_operation(s_node **b_stack, size_t search_value)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	s_node *searchnode;
	searchnode = *b_stack;

	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	while(searchnode->coord_num != search_value)
	{	
		//printf(" %lli > %zu \n", searchnode->coord_num, search_range_max);
		searchnode = searchnode->prev;
		if(searchnode->coord_num != NIL)
			prev_dist_to_destination++;
	}
	searchnode = *b_stack;
	while(searchnode->coord_num != search_value)
	{
		searchnode = searchnode->next;
		next_dist_to_destination++;
	}
	//printf(" ---- %zu - %zu ---- \n", next_dist_to_destination, prev_dist_to_destination);
	if(next_dist_to_destination < prev_dist_to_destination)
	{
		while(next_dist_to_destination--)
			rb(b_stack, 1);
	}
	else
	{
		while(prev_dist_to_destination--)
			rrb(b_stack, 1);
	}
	//printf("======================%zu======================\n",search_range_max);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
}

void sort_six_or_less(size_t n, s_node **a_stack, s_node **b_stack)
{
	size_t search_coord_num;
	search_coord_num = 0;
	while(ft_get_stacksize(*a_stack) > 3)
	{
		if((*a_stack)->coord_num == search_coord_num)
		{
			pb(a_stack, b_stack);
			search_coord_num++;
		}
		else
			search_value_operation(a_stack, search_coord_num);
	}
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	sort_three_or_less(ft_get_stacksize(*a_stack), a_stack);
	while((*b_stack)->num != NIL)
		pa(a_stack, b_stack);
}


void search_rangevalue_operation(s_node **a_stack, size_t search_range_max)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	s_node *searchnode;
	searchnode = *a_stack;

	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	while(searchnode->coord_num > search_range_max)
	{	
		//printf(" %lli > %zu \n", searchnode->coord_num, search_range_max);
		searchnode = searchnode->prev;
		if(searchnode->coord_num != NIL)
			prev_dist_to_destination++;
	}
	searchnode = *a_stack;
	while(searchnode->coord_num > search_range_max)
	{
		searchnode = searchnode->next;
		next_dist_to_destination++;
	}
	//printf(" ---- %zu - %zu ---- \n", next_dist_to_destination, prev_dist_to_destination);
	if(next_dist_to_destination < prev_dist_to_destination)
	{
		while(next_dist_to_destination--)
			ra(a_stack, 1);
	}
	else
	{
		while(prev_dist_to_destination--)
			rra(a_stack, 1);
	}
	//printf("======================%zu======================\n",search_range_max);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
}
void sort_seven_or_more(size_t n, s_node **a_stack, s_node **b_stack)
{
	size_t push_range;
	size_t search_range_max;
	size_t pb_cnt;
	pb_cnt = 0;
	//===========================

	if(n < 10)
		push_range = 2;
	else if(10 <= n && n <= 100)
		push_range = 15;
	else if(100 < n && n < 500)
		push_range = 20;
	else
		push_range = 31;
	//===========================
	search_range_max = push_range;
	while((*a_stack)->coord_num != NIL)
	{
		search_rangevalue_operation(a_stack, search_range_max);
		pb(a_stack, b_stack);
		if(pb_cnt%2 == 1)
			rb(b_stack, 1);
		if((*b_stack)->next->coord_num != NIL && (*b_stack)->coord_num < (*b_stack)->next->coord_num)
		{
			if((*a_stack)->next->coord_num != NIL && (*a_stack)->coord_num > (*a_stack)->next->coord_num)
				ss(a_stack, b_stack);
			else
				sb(b_stack, 1);
		}
		pb_cnt++;
		if(pb_cnt == push_range)
		{
			pb_cnt = 0;
			if(SIZE_MAX-push_range < search_range_max)
				search_range_max = SIZE_MAX;
			else
				search_range_max += push_range;
		}
	}
	//===========================
	size_t search_value;
	search_value = n-1;
	while((*b_stack)->coord_num != NIL)
	{
		search_value_operation(b_stack, search_value);
		pa(a_stack, b_stack);
		search_value--;
	}
	
}


