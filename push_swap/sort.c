#include "push_swap.h"
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

void search_value_one_operation(s_node **a_stack, size_t destination)
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
		ra(a_stack, 1);
	else
		rra(a_stack, 1);
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
			search_value_one_operation(a_stack, search_coord_num);
	}
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	sort_three_or_less(ft_get_stacksize(*a_stack), a_stack);
	while((*b_stack)->num != NIL)
		pa(a_stack, b_stack);
}

//bのmiddleより以上をpaする
void b_middle_upper_pa(size_t b_middle, size_t *search_idx, s_node **a_stack, s_node **b_stack)
{
	size_t n;
	n = ft_get_stacksize(*b_stack);
	while(n--)
	{
		if(b_middle <= (*b_stack)->coord_num)
			pa(a_stack, b_stack);
		else
			rb(b_stack, 1);
	}

}

//bのmiddleより下をpaする
void b_middle_lower_pa(size_t b_middle,size_t *search_idx, s_node **a_stack, s_node **b_stack)
{
	size_t n;
	n = ft_get_stacksize(*b_stack);
	while(n--)
	{
		if(b_middle > (*b_stack)->coord_num)
		{
			pa(a_stack, b_stack);
			if((*a_stack)->coord_num == *search_idx)
			{
				ra(a_stack, 1);
				*search_idx = *search_idx + 1;
				printf("search_idx = %zu\n", *search_idx);
			}
		}
		else
			rb(b_stack, 1);
	}


}

void quicksort(size_t range, size_t middle, size_t *search_idx, s_node **a_stack, s_node **b_stack)
{
	if(middle < *search_idx || middle == 1 || middle == 0)
		return;
	//aのmiddle以下の値をpbする
	while(range--)//b_middle - search_idx回
	{
		if(middle >= (*a_stack)->coord_num)
			pb(a_stack,b_stack);
	}
	
	size_t b_middle = middle/2;
	//ここにmiddle以上だった数字の処理
}


void sort_seven_or_more(size_t n, size_t search_idx,  s_node **a_stack, s_node **b_stack)
{
	size_t middle;
	size_t b_middle;
	//size_t search_idx;
	//search_idx = 0;
	middle = n/2;
	
	if(search_idx == 0)
	{
		while(n--)
		{
			if(middle > (*a_stack)->coord_num)
				pb(a_stack,b_stack);
			else	
				ra(a_stack, 1);
		}
	}
	else if((*a_stack)->coord_num >= middle/2)
	{
		while(middle < (*a_stack)->coord_num < b_middle)
	}
	else
	{
		while((*a_stack)->coord_num > middle)
			pb(a_stack, b_stack);
	}
	b_middle = middle/2;
	b_middle_upper_pa(middle/2,search_idx, a_stack, b_stack);
	b_middle_lower_pa(middle/2,search_idx, a_stack, b_stack);
	//conf_stack(ft_get_stacksize(*a_stack),*a_stack,1);
	//conf_stack(ft_get_stacksize(*b_stack),*b_stack,0);
	sort_seven_or_more(middle/2, search_idx ,a_stack, b_stack);


}

