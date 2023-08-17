#include "push_swap.h"
//s--------------------------------------------------------------
s_node *sa(size_t n, s_node **stack) 
{
	if(!stack)
		printf("sa: stackが存在しない");
	s_node *nil_node;
	s_node *first_node;
	s_node *second_node;
	s_node *third_node;
	nil_node  = (*stack)->prev;
	first_node  = (*stack);
	second_node  = (*stack)->next;
	third_node = (*stack)->next->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->prev = nil_node;
	second_node->next = first_node;
	if(n == 2)
		nil_node->prev = first_node;
	else if(n >= 3)
		third_node->prev = first_node;
	nil_node->next = second_node;
	//if(isa)
	//	write(1, "sa\n", 3);
	//else
	//	write(1, "sb\n", 3);
	return second_node;
}

//void ss(s_node **a_stack, s_node **b_stack) 
//{
//	//sa,sbをまとめて、実行時のlist状況に応じてssを実行するかを選択した方が冗長ではない
//	a_stack = sa(a_stack, b_stack);
//	a_stack = sb(a_stack, b_stack);
//	write(1, "ss\n", 3);
//}

//p--------------------------------------------------------------
void pa(s_node **a_stack, s_node **b_stack) 
{
	s_node *a_nil_node;
	s_node *b_nil_node;
	
	s_node *a_first_node;
	s_node *b_secondnode;
	size_t b_stack_len;
	write(1, "b", 1);
	b_stack_len = ft_get_stacksize(b_stack);
	write(1, "b", 1);
	if(*b_stack == 0 && (*b_stack)->num == NIL)
	{
		printf("pa: b_stackの要素が存在しません");
		return;
	}
	write(1, "b", 1);
	b_secondnode = (*b_stack)->next;
	b_nil_node = (*b_stack)->prev;

	if(b_stack_len == 1)
	{
		b_nil_node->prev = NULL;
		b_nil_node->next = NULL;
	}
	else if(b_stack_len >= 2)
		b_nil_node->next = (*b_stack)->next;
	(*b_stack)->prev = a_nil_node;
	(*b_stack)->next = *a_stack;
	(*a_stack)->prev = *b_stack;

	*a_stack = (*a_stack)->prev;	
	*b_stack = b_secondnode;
	
	a_nil_node->next = *a_stack;
	
	write(1, "pa\n", 3);
}
void pb(s_node **a_stack, s_node **b_stack) 
{
	s_node *a_nilnode;
	s_node *b_nilnode;
	s_node *a_secondnode;
	a_nilnode = (*a_stack)->prev;
	a_secondnode = (*a_stack)->next;
	printf("*b_stack = %p\n", *b_stack);
	printf("*b_stack prev = %p\n", (*b_stack)->prev);
	printf("*b_stack num = %lli\n", (*b_stack)->num);
	printf("*b_stack next = %p\n", (*b_stack)->next);

	if(*b_stack == 0)
		{printf("in add\n");ft_nodeadd_back(b_stack, ft_nodenew(NIL));}
	printf("by addback *b_stack = %p\n", *b_stack);
	printf("*b_stack = %lli\n", (*b_stack)->num);
	(*a_stack)->next->prev = a_nilnode;
	if((*b_stack)->num == NIL)
	{
		b_nilnode = *b_stack;
		(*a_stack)->prev = b_nilnode;
		(*a_stack)->next = b_nilnode;
		(b_nilnode)->prev = *a_stack;
	}
	else
	{
		b_nilnode = (*b_stack)->prev;
		(*a_stack)->prev = b_nilnode;
		(*a_stack)->next = (*b_stack);
	}
	write(1, "e", 1);
	printf("b_nilnode = %p\n", b_nilnode);
	printf("b_nilnode next  = %p\n", b_nilnode->next);
	printf("b_nilnode next = *b_stack = %p\n", *b_stack);
	printf("*a_stack  = %p\n", *a_stack);
	b_nilnode->next = *a_stack;

	write(1, "b", 1);
	*b_stack = *a_stack;
	*a_stack = a_secondnode;
	write(1, "pb\n", 3);
}
//r--------------------------------------------------------------
void ra(s_node *a_stack, s_node *b_stack) 
{
	
	write(1, "ra\n", 3);
}
void rb(s_node *a_stack, s_node *b_stack) 
{

	write(1, "rb\n", 3);
}
void rr(s_node *a_stack, s_node *b_stack) 
{
	
	write(1, "rr\n", 3);
}

//rr--------------------------------------------------------------
void rra(s_node *a_stack, s_node *b_stack) 
{
	
	write(1, "rra\n", 4);
}
void rrb(s_node *a_stack, s_node *b_stack) 
{

	write(1, "rrb\n", 4);
}
void rrr(s_node *a_stack, s_node *b_stack) 
{
	
	write(1, "rrr\n", 4);
}

