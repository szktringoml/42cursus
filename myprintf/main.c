/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:27:42 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/25 07:18:33 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "inc/ft_printf.h"
//#include "libft/libft.h"
//#include <unistd.h>
//#include <stdarg.h>
//#include <stdio.h>
//int main()
//{	
//	//-----%-----
//	printf("-----%%-----\n");
//	printf("      return = %i\n",printf("printf : %%\n"));
//	printf("      return = %i\n",ft_printf("ft_printf : %%\n")-3);
//	printf("\n");
//	
//	//-----c-----
//	printf("-----c-----\n");
//	printf("      return = %i\n",printf("printf : %c\n",'!'));
//	printf("      return = %i\n",ft_printf("ft_printf : %c\n",'!')-3);
//	printf("\n");
//
//	//-----s-----
//	printf("-----s-----\n");
//	printf("      return = %i\n",printf("printf : %s\n","Hello World"));
//	printf("      return = %i\n",ft_printf("ft_printf : %s\n","Hello World")-3);
//	//-----null_str-----
//	printf("-----null_str-----\n");
//	printf("      return = %i\n",printf("printf : %s\n",""));
//	printf("      return = %i\n",ft_printf("ft_printf : %s\n","")-3);
//
//	printf("\n");
//
//	//-----s & c-----
//	printf("-----s & c-----\n");
//	printf("      return = %i\n",printf("printf : %s%c\n","Hello World",'!'));
//	printf(" 	  return = %i\n",ft_printf(
//	"ft_printf : %s%c\n","Hello World",'!')-3);
//	printf("\n");
//
//	//-----d & i & u-----
//	printf("-----d & i & u-----\n");
//	printf("      return = %i\n",printf("printf : %d  %i  %u\n",-500,-500,-500));
//	printf("	  return = %i\n",ft_printf(
//	"ft_printf : %d  %i  %u\n",-500,-500,-500)-3);
//	printf("\n");
//
//	//-----p-----
//	printf("-----p-----\n");
//	int c;
//	int *p = &c;
//	printf("      return = %i\n",printf("printf : %p\n", p));
//	printf("      return = %i\n",ft_printf("ft_printf : %p\n", p)-3);
//	printf("\n");
//	
//	//-----p(void *)0-----
//	printf("-----p(void *)0-----\n");
//	printf("      return = %i\n",printf("printf : %p\n", p));
//	printf("      return = %i\n",ft_printf("ft_printf : %p\n", (void *)0)-3);
//	printf("\n");
//
//	//-----x-----
//	printf("-----x-----\n");
//	printf("      return = %i\n",printf("printf : %x\n", 3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %x\n",3000)-3);
//	printf("\n");
//
//	//-----x(case zero)-----
//	printf("-----x(case 0)-----\n");
//	printf("      return = %i\n",printf("printf : %x\n", 0));
//	printf("      return = %i\n",ft_printf("ft_printf : %x\n",0)-3);
//	printf("\n");
//
//	//-----x(case minus)-----
//	printf("-----x(case minus)-----\n");
//	printf("      return = %i\n",printf("printf : %x\n", -3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %x\n",-3000)-3);
//	printf("\n");
//
//	//-----X-----
//	printf("-----X-----\n");
//	printf("      return = %i\n",printf("printf : %X\n", 3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %X\n",3000)-3);
//	printf("\n");
//
//	//-----X(case zero)-----
//	printf("-----X(case zero)-----\n");
//	printf("      return = %i\n",printf("printf : %X\n", 0));
//	printf("      return = %i\n",ft_printf("ft_printf : %X\n", 0)-3);
//	printf("\n");
//
//	//-----X(case minus)-----
//	printf("-----X(case minus)-----\n");
//	printf("      return = %i\n",printf("printf : %X\n", -3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %X\n", -3000)-3);
//	printf("\n");
//	
//	////----------
//	//printf("      return = %\n",printf("printf : %\n", ));
//	//printf("      return = %\n",ft_printf("ft_printf : %\n",)-3);
//	//printf("\n");
//
//	//=======================BONUS=========================
//	printf("=======================BONUS=========================");
//	printf("\n");
//
//	//-----#x-----
//	printf("-----#x-----\n");
//	printf("      return = %i\n",printf("printf : %#x\n", 3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %#x\n",3000)-3);
//	printf("\n");
//	
//	//-----#X-----
//	printf("-----#X-----\n");
//	printf("      return = %i\n",printf("printf : %#X\n", 3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %#X\n",3000)-3);
//	printf("\n");
//	
//	//-----+d-----
//	printf("-----+d-----\n");
//	printf("      return = %i\n",printf("printf : %+d\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+d\n",500)-3);
//	printf("\n");
//	
//	//-----+i-----
//	printf("-----+i-----\n");
//	printf("      return = %i\n",printf("printf : %+i\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+i\n",500)-3);
//	printf("\n");
//	
//	//-----+u-----
//	printf("-----+u-----\n");
//	//printf("      return = %i\n",printf("printf : %+u\n", 500));
//	//printf("      return = %i\n",ft_printf("ft_printf : %+u\n",500)-3);
//	printf("\n");
//	
//	//----- d-----
//	printf("----- d-----\n");
//	printf("      return = %i\n",printf("printf : % d\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : % d\n",500)-3);
//	printf("\n");
//	
//	//----- d(d = 0)-----
//	printf("----- d(d = 0)-----\n");
//	printf("      return = %i\n",printf("printf : % d\n", 0));
//	printf("      return = %i\n",ft_printf("ft_printf : % d\n", 0)-3);
//	printf("\n");
//
//	//----- i-----
//	printf("----- i-----\n");
//	printf("      return = %i\n",printf("printf : % i\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : % i\n",500)-3);
//	printf("\n");
//
//	//----- u-----
//	//printf("      return = %i\n",printf("printf : % u\n", 500));
//	//printf("      return = %i\n",ft_printf("ft_printf : % u\n",500)-3);
//
//	//-----+ d-----
//	printf("-----+ d-----\n");
//	//printf("      return = %i\n",printf("printf : %+ d\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+ d\n",500)-3);
//	printf("\n");
//	
//	//-----+ d(d = 0)-----
//	printf("-----+ d(d = 0)-----\n");
//	//printf("      return = %i\n",printf("printf : %+ d\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+ d\n",500)-3);
//	printf("\n");
//
//	//-----+ i-----
//	printf("-----+ i-----\n");
//	//printf("      return = %i\n",printf("printf : %+ i\n", 500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+ i\n",500)-3);
//	printf("\n");
//
//	//-----+ u-----
//	//printf("      return = %i\n",printf("printf : % u\n", 500));
//	//printf("      return = %i\n",ft_printf("ft_printf : % u\n",500)-3);
//	printf("\n");
//
//	//=======================BONUS MINUS VALUE=========================
//	printf("=======================BONUS MINUS VALUE=========================");
//	printf("\n");
//
//	//-----#x-----
//	printf("-----#x-----\n");
//	printf("      return = %i\n",printf("printf : %#x\n", -3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %#x\n",-3000)-3);
//	printf("\n");
//	
//	//-----#X-----
//	printf("-----#X-----\n");
//	printf("      return = %i\n",printf("printf : %#X\n", -3000));
//	printf("      return = %i\n",ft_printf("ft_printf : %#X\n",-3000)-3);
//	printf("\n");
//	
//	//-----+d-----
//	printf("-----+d-----\n");
//	printf("      return = %i\n",printf("printf : %+d\n", -500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+d\n",-500)-3);
//	printf("\n");
//	
//	//-----+i-----
//	printf("-----+i-----\n");
//	printf("      return = %i\n",printf("printf : %+i\n", -500));
//	printf("      return = %i\n",ft_printf("ft_printf : %+i\n",-500)-3);
//	printf("\n");
//	
//	//-----+u-----
//	//printf("      return = %i\n",printf("printf : %+u\n", -500));
//	//printf("      return = %i\n",ft_printf("ft_printf : %+u\n",-500)-3);
//	printf("\n");
//	
//	//----- d-----
//	printf("----- d-----\n");
//	printf("      return = %i\n",printf("printf : % d\n", -500));
//	printf("      return = %i\n",ft_printf("ft_printf : % d\n",-500)-3);
//	printf("\n");
//	
//	//----- i-----
//	printf("----- i-----\n");
//	printf("      return = %i\n",printf("printf : % i\n", -500));
//	printf("      return = %i\n",ft_printf("ft_printf : % i\n",-500)-3);
//	printf("\n");
//	
//	//----- u-----
//	//printf("      return = %i\n",printf("printf : % u\n", -500));
//	//printf("      return = %i\n",ft_printf("ft_printf : % u\n",-500)-3);
//	printf("\n");
//
//
//	return 0;
//}
