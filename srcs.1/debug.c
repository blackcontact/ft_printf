/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:01:34 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 11:54:56 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			debug(t_conversion *test)
{
	//for (int i = 0; i < 5; i++)
	//	fprintf(stderr, "flags[%i] = '%c'\n",i, test->flags[i]);
	fprintf(stderr, "min = '%d'\n", test->min_width);
	fprintf(stderr, "max = '%d'\n", test->precision);
	fprintf(stderr, "length = '%c'\n", test->length);
	fprintf(stderr, "type = '%c'\n", test->type);
	fprintf(stderr, "value = '%d'\n", (int)test->value);
}
