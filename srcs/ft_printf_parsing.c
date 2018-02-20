/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:05:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:50:28 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_flags(const char **nav, t_conversion *result)
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

static void		parse_minwidth(const char **nav, t_conversion *r, va_list ap)
{
	int stop;

	stop = 1;
	while (stop)
	{
		stop = 0;
		while (ft_isdigit(**nav))
		{
			r->min_width = ft_atoi(*nav);
			while (ft_isdigit(**nav))
				(*nav)++;
			stop = 1;
		}
		if (**nav == '*')
		{
			stop = 1;
			r->min_width = va_arg(ap, int);
			(*nav)++;
			if (r->min_width < 0)
			{
				r->min_width *= -1;
				r->flags[2] = '-';
			}
		}
	}
}

static void		parse_precision(const char **nav, t_conversion *r, va_list ap)
{
	int		stop;

	(*nav)++;
	stop = 1;
	r->precision_isset = 1;
	while (stop)
	{
		stop = 0;
		while (ft_isdigit(**nav))
		{
			r->precision = (r->precision * 10) + (**nav - '0');
			(*nav)++;
			stop = 1;
			r->precision_isset = 1;
		}
		if (**nav == '*')
		{
			r->precision_isset = 1;
			stop = 1;
			r->precision = va_arg(ap, int);
			(*nav)++;
			if (r->precision < 0)
				r->precision_isset = 0;
		}
	}
}

static void		parse_length(const char **nav, t_conversion *result)
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

t_conversion	*printf_parsing(const char **nav, va_list ap)
{
	t_conversion	*result;

	if (!(result = malloc(sizeof(t_conversion))))
		return (NULL);
	(*nav)++;
	struct_blank(result);
	parse_flags(nav, result);
	parse_minwidth(nav, result, ap);
	if (**nav == '.')
		parse_precision(nav, result, ap);
	parse_length(nav, result);
	parse_flags(nav, result);
	result->type = **nav;
	if (**nav)
		(*nav)++;
	if (result->type != '%' && !parse_false(result))
		result->value = va_arg(ap, void *);
	return (result);
}
