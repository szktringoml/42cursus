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
void conf_stack(size_t n, s_node **a_stack)
{
	size_t i=0;
	while(i<n+1)
	{
		printf("-------*a_stack= %lli ------\n",(*a_stack)->num);
		printf(" *a_stack->prev= %lli \n",(*a_stack)->prev->num);
		printf(" *a_stack->next= %lli \n",(*a_stack)->next->num);
		printf("\n");
		*a_stack = (*a_stack)->next;
		i++;	
	}
}

void nodeinit(s_node **a_stack, s_node **b_stack)
{
	s_node *a_nullnode;
	s_node *b_nullnode;
	//新しくnodeを作成しa_stack = &nodeとする
	a_nullnode = ft_nodenew(NIL);
	b_nullnode = ft_nodenew(NIL);
	
	a_stack = a_nullnode;
	b_stack = b_nullnode;
}
	

int main(int argc, char *argv[])
{
	//s_list list;
	size_t n;
	s_node **a_stack;
	s_node **b_stack;
	//入力値のエラー処理
	n = inputcheck_argcount(argc, 0, argv);//ちゃんとここまで動くか
	printf("値の数n = %zu\n", n);
	//nodeへの値の格納
	nodeinit(a_stack, b_stack);
	printf("nodeinit finish\n");
	
	storenode(argc, argv, a_stack);
	printf("storenode finish\n");
	//座標圧縮
 	coordinate_compression(n, *a_stack);
	printf("coordinate_compression finish\n");
	if(issort)	
	//a_stackの各参照アドレス確認用
	conf_stack(n, a_stack);
	//*a_stack = sa(n, a_stack);
	
	printf("*a_stack = %p\n", *a_stack);
	printf("b_stack = %p\n", b_stack);
	printf("*b_stack = %p\n", *b_stack);
	pb(a_stack, b_stack);
	conf_stack(n, a_stack);
	//n <= 3の時

	//n < 7 の時

	//n >= 7の時
	
	return 0;
}
