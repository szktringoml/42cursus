#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct t_node{
	struct t_node *prev;
	long long num;
	int coord_num;
	struct t_node *next;
}	s_node;

int isinc_space_str(const char *str);

int isnumsign_str(const char *str);

int inputcheck_argcount(int argc, int n, char *argv[]);

s_node *ft_nodenew(long long num);

void ft_nodeadd_back(s_node **a_stack, s_node *new);

s_node *ft_nodelast(s_node *a_stack);

void storenode(int argc, char *argv[], s_node **a_stack);

void coordinate_compression(size_t n, s_node *a_stack);

size_t ft_get_stacksize(s_node **stack);

s_node *sa(size_t n, s_node **stack);

void pb(s_node **a_stack, s_node **b_stack);

#define NIL 2147483648

#endif
