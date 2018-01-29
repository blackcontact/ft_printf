/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:16:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:41:22 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int		main(void)
{
	int		i;
	int		j;

	setlocale(LC_ALL, "");
	j = ft_printf("%#llx\n", 9223372036854775807);
	//i =    printf("R|% Z%s\n", "test");
	//printf("mine res=%d\n", j);
	//printf("real res=%d\n", i);
	return (0);
}
