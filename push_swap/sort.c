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

void search_value_operation(s_node **a_stack, size_t destination)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	s_node *firstnode;
	firstnode = *a_stack;

	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	while(firstnode->prev->coord_num != destination)
	{	
		prev_dist_to_destination++;
		firstnode = firstnode->prev;
	}
	firstnode = *a_stack;
	while(firstnode->next->coord_num != destination)
	{
		next_dist_to_destination++;
		firstnode = firstnode->next;
	}
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
	s_node *firstnode;
	firstnode = *a_stack;

	prev_dist_to_destination = 1;
	next_dist_to_destination = 1;
	printf("loop1\n");
	while( firstnode->prev->coord_num > search_range_max)
	{	
		printf(" %lli > %zu \n", firstnode->prev->coord_num, search_range_max);
		if(firstnode->prev->coord_num != NIL)
			prev_dist_to_destination++;
		firstnode = firstnode->prev;
		//printf("firstnode -> prev -> coordnum = %lli \n", firstnode->prev->coord_num);
	}
	firstnode = *a_stack;
	printf("loop2\n");
	while(firstnode->next->coord_num > search_range_max)
	{
		next_dist_to_destination++;
		firstnode = firstnode->next;
	}
	printf("loop3\n");
	printf(" ---- %zu - %zu ---- \n", next_dist_to_destination, prev_dist_to_destination);
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
	printf("======================%zu======================\n",search_range_max);
	conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
}
void sort_seven_or_more(size_t n, s_node **a_stack, s_node **b_stack)
{
	size_t push_range;
	size_t search_range_max;
	size_t push_cnt_remaining;
	size_t push_cnt;
	search_range_max = 0;
	push_cnt = 0;
	//===========================

	if(n < 10)
		push_range = 2;
	else if(10 <= n && n <= 100)
		push_range = 3;
	else if(100 <= n && n <= 1000)
		push_range = 10;
	else
		push_range = 20;
	//===========================
	while((*a_stack)->coord_num != NIL)
	{
		push_cnt_remaining = push_range;
		search_range_max = search_range_max + push_range;
		while( push_cnt_remaining)
		{
			if((*a_stack)->coord_num < search_range_max)
			{
				push_cnt++;
				pb(a_stack, b_stack);
				if(push_cnt%2 == 0)//最適化
					rb(b_stack, 1);
				push_cnt_remaining--;
			}
			else
				search_rangevalue_operation(a_stack, search_range_max);
		}
	}
	//===========================

}


