/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:16:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:29:53 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>

int		main(void)
{
	/*int ftret, reret;
	//setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	//printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);
	ftret = ft_printf("||%-010s||\n", "this");
	printf("\n");
	reret =    printf("{{%-010s}}\n", "this");
	printf("\n");
	printf("ftret = %d || reret = %d\n", ftret, reret);
	return (0);*/
	/*ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter");
	ft_printf("Il fait au moins %c", -8000);
	ft_printf("%c", 0);
	ft_printf("%c", 0);
	ft_printf("%c\n");
	ft_printf("%c", 42);
	ft_printf("%c", 42);*/
	   printf("REAL = {%*3d}\n", 5, 0);
	ft_printf("MINE = {%*3d}\n", 5, 0);
	//ft_printf("balbalba %c fgflglfdg\n", 458721);
}
