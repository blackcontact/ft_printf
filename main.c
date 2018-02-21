/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:16:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 14:05:57 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include <math.h>

int		main(void)
{
	int	test;

	test = ft_printf("Salut comment {magenta}tu va{eoc}s %b he\n", 10);
	printf("%d", test);
}
