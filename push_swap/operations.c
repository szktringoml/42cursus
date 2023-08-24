#include "push_swap.h"
//s--------------------------------------------------------------
void sa(s_node **a_stack, int iswrite) 
{
	s_node *nil_node;
	s_node *second_node;
	s_node *third_node;
	size_t stacksize;

	stacksize = ft_get_stacksize(*a_stack);
	if(stacksize == 0)
	{	
		printf("sa: stackが存在しない");
		exit(0);
	}
	else if(stacksize == 1)
	{
		printf("sb: stackの要素が1つしかない");
		exit(0);
	}

	nil_node  = (*a_stack)->prev;
	second_node  = (*a_stack)->next;

	(*a_stack)->prev = second_node;
	second_node->prev = nil_node;
	nil_node->next = second_node;
	if(stacksize == 2)
	{
		nil_node->prev = (*a_stack);
		(*a_stack)->next = nil_node;
	}
	else
	{
		third_node = second_node->next;
		(*a_stack)->next = third_node;
		third_node->prev = (*a_stack);
	}
	second_node->next = (*a_stack);
	//if(isa)
	*a_stack = second_node;
	if(iswrite)
		write(1, "sa\n", 3);
	//else
	//	write(1, "sb\n", 3);
}

void sb(s_node **b_stack, int iswrite) 
{
	if((*b_stack)->num == NIL)
		printf("sa: stackが存在しない");
	if((*b_stack)->next->num == NIL)
		printf("sb: stackの要素が1つしかない");
	s_node *nil_node;
	s_node *first_node;
	s_node *second_node;
	s_node *third_node;
	nil_node  = (*b_stack)->prev;
	first_node  = (*b_stack);
	second_node  = (*b_stack)->next;
	third_node = (*b_stack)->next->next;
	first_node->prev = second_node;
	first_node->next = third_node;
	second_node->prev = nil_node;
	second_node->next = first_node;

	//nil_nodeのprevはstackの数による
	if(ft_get_stacksize(*b_stack) == 2)
		nil_node->prev = first_node;
	else
		third_node->prev = first_node;
	nil_node->next = second_node;
	//if(isa)
	//	write(1, "sa\n", 3);
	//else
	if(iswrite)
		write(1, "sb\n", 3);
	*b_stack = second_node;
}
void ss(s_node **a_stack, s_node **b_stack) 
{
	//sa,sbをまとめて、実行時のlist状況に応じてssを実行するかを選択した方が冗長ではない
	sa(a_stack, 0);
	sb(b_stack, 0);
	write(1, "ss\n", 3);
}

//p--------------------------------------------------------------

void pa(s_node **a_stack, s_node **b_stack) 
{
	if((*b_stack)->num == NIL)
	{
		printf("pb: b_stackの要素がない");
		exit(0);
	}
	s_node *a_nilnode;
	s_node *b_nilnode;
	s_node *b_secondnode;
	a_nilnode = (*a_stack)->prev;
	b_secondnode = (*b_stack)->next;
	//b_stack
	if(b_secondnode->num == NIL)
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
	//a_stack
	(*a_stack)->prev = (*b_stack);
	(*b_stack)->prev = a_nilnode;
	(*b_stack)->next = (*a_stack);
	a_nilnode->next = (*b_stack);
	//head update
	(*a_stack) = (*b_stack);
	(*b_stack) = b_secondnode;
	
	write(1, "pa\n", 3);
}

void pb(s_node **a_stack, s_node **b_stack) 
{
	s_node *a_nilnode;
	s_node *b_nilnode;
	s_node *a_secondnode;
	a_nilnode = (*a_stack)->prev;
	a_secondnode = (*a_stack)->next;

	a_secondnode->prev = a_nilnode;
	if((*b_stack)->num == NIL)
	{
		b_nilnode = *b_stack;
		(*a_stack)->prev = b_nilnode;
		(*a_stack)->next = b_nilnode;
		(b_nilnode)->prev = *a_stack;
		(b_nilnode)->next = *a_stack;
	}
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
//r--------------------------------------------------------------
void ra(s_node **a_stack, int iswrite) 
{
	s_node *nilnode;
	s_node *lastnode;
	s_node *secondnode;
	nilnode = (*a_stack)->prev;
	lastnode = nilnode->prev;
	secondnode = (*a_stack)->next;

	if(ft_get_stacksize(*a_stack) == 1)
	{
		printf("ra: 要素が一つしかない");
		exit(0);
	}
	else if(ft_get_stacksize(*a_stack) == 2)
		sa(a_stack, 0);
	else
	{
		lastnode->next = (*a_stack);
		nilnode->prev = (*a_stack);
		nilnode->next = (*a_stack)->next;
		secondnode->prev = nilnode;
		(*a_stack)->prev = lastnode;
		(*a_stack)->next = nilnode;
		
		*a_stack = secondnode;
	}
	if(iswrite)
		write(1, "ra\n", 3);
}

void rb(s_node **b_stack, int iswrite) 
{
	if(ft_get_stacksize(*b_stack) == 0)
	{
		printf("rb: 要素がない");
		exit(0);
	}
	s_node *nilnode;
	s_node *lastnode;
	s_node *secondnode;
	nilnode = (*b_stack)->prev;
	lastnode = nilnode->prev;
	secondnode = (*b_stack)->next;

	if(ft_get_stacksize(*b_stack) == 1)
	{
		printf("ra: 要素が一つしかない");
		exit(0);
	}
	else if(ft_get_stacksize(*b_stack) == 2)
		sb(b_stack, 0);
	else
	{
		lastnode->next = (*b_stack);
		nilnode->prev = (*b_stack);
		nilnode->next = (*b_stack)->next;
		secondnode->prev = nilnode;
		(*b_stack)->prev = lastnode;
		(*b_stack)->next = nilnode;
		
		*b_stack = secondnode;
	}
	if(iswrite)
		write(1, "rb\n", 3);
}
void rr(s_node **a_stack, s_node **b_stack) 
{
	ra(a_stack, 0);
	rb(b_stack, 0);	
	write(1, "rr\n", 3);
}

//rr--------------------------------------------------------------
void rra(s_node **a_stack, int iswrite) 
{
	s_node *nilnode;
	s_node *lastnode;
	s_node *last_secondnode;
	nilnode = (*a_stack)->prev;
	lastnode = nilnode->prev;

	if(ft_get_stacksize(*a_stack) == 1)
	{
		printf("rra: 要素が一つしかない");
		exit(0);
	}
	last_secondnode = nilnode->prev->prev;
	
	nilnode->prev = last_secondnode;
	nilnode->next = lastnode;
	lastnode->prev = nilnode;
	lastnode->next = (*a_stack);
	(*a_stack)->prev = lastnode;
	last_secondnode->next = nilnode;

	*a_stack = lastnode;
	if(iswrite)
		write(1, "rra\n", 4);
}

void rrb(s_node **b_stack, int iswrite) 
{
	if(ft_get_stacksize(*b_stack) == 1 || ft_get_stacksize(*b_stack) == 0)
	{
		printf("rra: 要素が1つしかない または 0");
		exit(0);
	}
	s_node *nilnode;
	s_node *lastnode;
	s_node *last_secondnode;
	nilnode = (*b_stack)->prev;
	lastnode = nilnode->prev;

	last_secondnode = nilnode->prev->prev;
	
	nilnode->prev = last_secondnode;
	nilnode->next = lastnode;
	lastnode->prev = nilnode;
	lastnode->next = (*b_stack);
	(*b_stack)->prev = lastnode;
	last_secondnode->next = nilnode;

	*b_stack = lastnode;
	if(iswrite)
		write(1, "rrb\n", 4);
}

void rrr(s_node **a_stack, s_node **b_stack) 
{
	rra(a_stack, 0);
	rrb(b_stack, 0);

	write(1, "rrr\n", 4);
}

