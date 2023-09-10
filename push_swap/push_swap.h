#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../libft/libft.h"

typedef struct t_node{
	struct t_node *prev;
	long long num;
	long long coord_num;
	struct t_node *next;
}	s_node;

int ft_abs(size_t a, size_t b)
void conf_stack(size_t n, s_node *stack, int isa);
int isinc_space_str(const char *str);

int isnumsign_str(const char *str);

int inputcheck_argcount(int argc, int n, char *argv[]);

s_node *ft_nodenew(long long num);

void ft_nodeadd_back(s_node **a_stack, s_node *newnode);

s_node *ft_nodelast(s_node *a_stack);

void storenode(int argc, char *argv[], s_node **a_stack);

void coordinate_compression(size_t n, s_node *a_stack);

int issorted(s_node *a_stack);

size_t ft_get_stacksize(s_node *stack);

void sa(s_node **a_stack, int iswrite);

void sb(s_node **b_stack, int iswrite);

void ss(s_node **a_stack, s_node **b_stack);

void pa(s_node **a_stack, s_node **b_stack);

void pb(s_node **a_stack, s_node **b_stack);

void ra(s_node **a_stack, int iswrite);

void rb(s_node **b_stack, int iswrite);

void rr(s_node **a_stack, s_node **b_stack);

void rra(s_node **a_stack, int iswrite);

void rrb(s_node **b_stack, int iswrite);

void rrr(s_node **a_stack, s_node **b_stack);

void sort_three_or_less(size_t n, s_node **stack);

void search_value_operation(s_node **a_stack, size_t destination);
void sort_six_or_less(size_t n, s_node **a_stack, s_node **b_stack);

void search_rangevalue_operation(s_node **a_stack,s_node **b_stack,  size_t search_range_max);
void sort_seven_or_more(size_t n,s_node **a_stack, s_node **b_stack);

#define NIL 2147483648

#endif
