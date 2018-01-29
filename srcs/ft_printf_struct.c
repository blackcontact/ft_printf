/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_struct.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 11:05:58 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:32:57 by mschneid    ###    #+. /#+    ###.fr     */
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
	ret->output = NULL;
}

int				parse_verif(t_conversion *result)
{
	if (result->type == 0)
		return (-1);
	return (0);
}

t_conversion	*printf_parsing(const char **nav, va_list ap)
{
	t_conversion	*result;

	if (!(result = malloc(sizeof(t_conversion))))
		return (NULL);
	(*nav)++;
	struct_blank(result);
	parse_flags(nav, result);
	parse_minwidth(nav, result);
	parse_precision(nav, result);
	parse_length(nav, result);
	parse_type(nav, result);
	if (parse_verif(result))
	{
		free(result);
		return (NULL);
	}
	result->value = va_arg(ap, void *);
	return (result);
}
