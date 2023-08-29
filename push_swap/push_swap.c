#include "push_swap.h"

int isinc_space_str(const char *str)
{
	size_t i;
	i = 0;	
	while(str[i])
	{
		if(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return 1;
		i++;
	}
	return 0;	
}

int isnumsign_str(const char *str)
{
	size_t i;
	i = 0;
	//printf("\nisnumsign_str: str = %s\n", str);
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
	{
		if(ft_isdigit(str[i]))
			i++;
		else
			return 0;
	}
	return 1;
}

//void issorted(s_node *init_a_stack)
//{
//	if(ft_get_stacksize(init_a_stack) == 1)
//		return 1;
//	while(a_stack->next->num != NIL)
//	{
//		now = a_stack->coord_num;
//		next = a_stack->next->coord_num;
//		if(now >= next)
//		if(a_stack->next 
//		a_stack = a_stack->next;
//		
//	
//
//	return 0;
//}
//void like_quicksort(size_t n, s_node *a_stack)
//{
//	s_node **b_stack;
//	while(a_stack->next != NIL)
//	{
//		if(a_stack->coord_num < (n/2))
//			//bにpush
//			pb(a_stack, *b_stack);
//		a_stack = a_stack->next;
//	}
//	while(b_stack
void conf_stack(size_t n, s_node *stack, int isa)
{
	size_t i=0;
	if(isa)
		printf("=====================a_stack status=====================\n");
	else
		printf("=====================b_stack status=====================\n");

	while(i<n+1)
	{
		printf("-------*stack= %lli: coordinate = %lli ------\n",stack->num, stack->coord_num);
		if(n > 0)
		{
			printf(" *stack->prev= %lli \n",stack->prev->num);
			printf(" *stack->next= %lli \n",stack->next->num);
		}
		else
		{
			printf(" *stack->prev= NULL \n");
			printf(" *stack->next= NULL \n");
		}
		printf("\n");
		stack = stack->next;
		i++;	
	}
	printf("======================================================\n");
}

void test(s_node **a_stack, s_node **b_stack){
	//test
	conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	rra(a_stack, 1);
	conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	pb(a_stack, b_stack);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	//ra(a_stack, 1);	
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	pb(a_stack, b_stack);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	//ra(a_stack, 1);	
	conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	conf_stack(ft_get_stacksize(*b_stack), *b_stack, 0);
	//ss(a_stack, b_stack);
	//conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	rrb(b_stack, 1);
	conf_stack(ft_get_stacksize(*b_stack), *b_stack, 0);
	rrr(a_stack, b_stack);
	conf_stack(ft_get_stacksize(*a_stack), *a_stack, 1);
	conf_stack(ft_get_stacksize(*b_stack), *b_stack, 0);

}


int main(int argc, char *argv[])
{
	//s_list list;
	size_t n;
	s_node *a_stack;
	s_node *b_stack;
	
	//入力値のエラー処理
	n = inputcheck_argcount(argc, 0, argv);//ちゃんとここまで動くか
	printf("値の数n = %zu\n", n);
	//nodeへの値の格納
	a_stack = ft_nodenew(NIL);
	
	storenode(argc, argv, &a_stack);
	printf("storenode finish\n");
	//座標圧縮
 	coordinate_compression(n, a_stack);
	printf("coordinate_compression finish\n");
	//ソート済みを弾く
	//if(issortd(a_stack))
	//	return 0;	
	b_stack = ft_nodenew(NIL);
	//test(&a_stack, &b_stack);	
	//n <= 3の時
	if(n <= 3)
		sort_three_or_less(n, &a_stack);
	else if(4 <= n && n <= 6)
		sort_six_or_less(n, &a_stack, &b_stack);
	else if(7 <= n)
		sort_seven_or_more(n, &a_stack, &b_stack);
	conf_stack(n, a_stack, 1);
	return 0;
}
