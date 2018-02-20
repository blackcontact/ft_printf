/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:05:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:37:16 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void			parse_flags(const char **nav, t_conversion *result)
{
	const char		flags[] = FLAGS;
	int				i;

	i = 0;
	while (i < 5)
	{
		if (flags[i] == **nav)
		{
			result->flags[i] = flags[i];
			i = 0;
			(*nav)++;
		}
		else
			i++;
	}
}

static void			parse_minwidth(const char **nav, t_conversion *result)
{
	while (ft_isdigit(**nav))
	{
		result->min_width = (result->min_width * 10) + (**nav - '0');
		(*nav)++;
	}
}

void				parse_precision(const char **nav, t_conversion *result)
{
	if (**nav != '.')
		return ;
	(*nav)++;
	result->precision_isset = 1;
	while (ft_isdigit(**nav))
	{
		result->precision = (result->precision * 10) + (**nav - '0');
		(*nav)++;
	}
}

static void			parse_length(const char **nav, t_conversion *result)
{
	const char		length[] = LENGTH;
	const char		*test = length;

	while (*test)
	{
		if (*test == **nav)
		{
			if (((**nav)) == 'L')
				result->length = 'm';
			else if (((*test) == (*((*nav) + 1))) && (*((*nav) + 1))
			&& (((*((*nav) + 1)) == 'h') || ((*((*nav) + 1)) == 'l')))
			{
				result->length = (**nav) - 32;
				(*nav)++;
			}
			else
				result->length = **nav;
			(*nav)++;
			break ;
		}
		test++;
	}
}

t_conversion		*printf_parsing(const char **nav, va_list ap)
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
	parse_flags(nav, result);
	result->type = **nav;
	if (**nav)
		(*nav)++;
	if (result->type != '%' && !parse_false(result))
		result->value = va_arg(ap, void *);
	return (result);
}
