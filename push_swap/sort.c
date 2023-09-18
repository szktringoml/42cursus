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

int ft_abs(size_t a, size_t b)
{
	int diff;
	diff = a - b;
	if(diff < 0)
		diff = diff * -1;
	return diff;
}

void search_rangevalue_operation(s_node **a_stack, s_node **b_stack, size_t search_range_max)
{
	//size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	s_node *searchnode;
	searchnode = *a_stack;

	//prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
//	while(searchnode->coord_num > search_range_max)
//	{	
//		searchnode = searchnode->prev;
//		if(searchnode->coord_num != NIL)
//			prev_dist_to_destination++;
//	}
//	searchnode = *a_stack;
	while(searchnode->coord_num > search_range_max)
	{
		searchnode = searchnode->next;
		next_dist_to_destination++;
	}
	//if(next_dist_to_destination < prev_dist_to_destination)
	//{
	while(next_dist_to_destination--)
		//if((*b_stack)->coord_num != NIL && (*b_stack)->next->coord_num != NIL && (ft_abs((*b_stack)->coord_num, (*b_stack)->prev->prev->coord_num)) < (ft_abs((*b_stack)->coord_num, (*b_stack)->next->coord_num)))
			//rr(a_stack, b_stack);
		//else
		ra(a_stack, 1);
	//}
	//else
	//{
	//	while(prev_dist_to_destination--)
	//		rra(a_stack, 1);
	//}
}

int search_value_operation_pa(s_node **a_stack, s_node **b_stack, size_t search_value)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	int isprev_push;
	s_node *searchnode;
	searchnode = *b_stack;
	
	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	isprev_push = 0;
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
		{
			if((*b_stack)->coord_num == search_value-1)
			{
				pa(a_stack, b_stack);
				isprev_push = 1;
			}
			else
				rb(b_stack, 1);
		}
	}
	else
	{
		while(prev_dist_to_destination--)
		{
			if((*b_stack)->coord_num == search_value-1)
			{
				pa(a_stack, b_stack);
				isprev_push = 1;
			}
			if((*b_stack)->next->coord_num != NIL)
				rrb(b_stack, 1);
		}
	}
	return isprev_push;
	//printf("======================%zu======================\n",search_range_max);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
}

void sort_seven_or_more(size_t n, s_node **a_stack, s_node **b_stack)
{
	size_t push_range;
	//===========================

	if(n < 10)
		push_range = 2;
	else if(10 <= n && n <= 100)
		push_range = n/10;
	else if(100 < n && n < 500)
		push_range = n/14;
	else
		push_range = n/14;
	//===========================
	size_t a_size = n;
	while((*a_stack)->coord_num != NIL && a_size > 3)
	{
		search_rangevalue_operation(a_stack,b_stack,  push_range);
		pb(a_stack, b_stack);
		if(push_range < n - 4)
			push_range++;
		if(a_size%2 == 0 && (*b_stack)->next->num != NIL 
			//&& (*b_stack)->prev->prev->coord_num < (ft_abs((*b_stack)->coord_num, (*b_stack)->next->coord_num))
			)
		{
			if((*a_stack)->coord_num > push_range)
				rr(a_stack,b_stack);
			else
				rb(b_stack, 1);
		}
		if((*b_stack)->coord_num != NIL && (*b_stack)->next->coord_num != NIL && (*b_stack)->coord_num < (*b_stack)->next->coord_num)
		{
			if((*a_stack)->next->coord_num != NIL && (*a_stack)->coord_num > (*a_stack)->next->coord_num)
				ss(a_stack, b_stack);
			else
				sb(b_stack, 1);
		}
		a_size--;
	}
	sort_three_or_less(3,a_stack);

	//===========================
	size_t search_value;
	search_value = n-4;
	int isprev_push;
	while((*b_stack)->coord_num != NIL)
	{
		isprev_push = search_value_operation_pa(a_stack, b_stack, search_value);
		pa(a_stack, b_stack);
		if(isprev_push)
		{
			if((*b_stack)->coord_num != NIL && (*b_stack)->next->coord_num != NIL && (*b_stack)->coord_num < (*b_stack)->next->coord_num)
				ss(a_stack, b_stack);
			else	
				sa(a_stack, 1);
			search_value--;
		}
		search_value--;
	}
}


