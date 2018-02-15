/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:16:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:55:31 by mschneid    ###    #+. /#+    ###.fr     */
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
	int		retft;
	int		ret;
	wchar_t	test;

	test = WCHAR_MAX;

	//setbuf(stdout, NULL);
	printf("%x\n", test);
	setlocale(LC_ALL, "");
	retft = ft_printf("@MINE=%C\n", test);
	ret = printf("@REAL=%C\n", test);
	printf("Real = %d\n", ret);
	printf("Ft = %d\n", retft);
	return (0);
}
