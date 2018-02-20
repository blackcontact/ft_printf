/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_struct.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 11:05:58 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:41:15 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			struct_blank(t_conversion *ret)
{
	ft_bzero(ret->flags, 6);
	ret->min_width = 0;
	ret->precision = 0;
	ret->length = 0;
	ret->type = 0;
	ret->precision_isset = 0;
	ret->value = NULL;
	ret->size = 0;
	ret->output = NULL;
}

int				parse_false(t_conversion *result)
{
	const char		types[] = TYPES;
	const char		*test = types;

	while (*test)
	{
		if (*test == result->type)
			return (0);
		test++;
	}
	return (1);
}
