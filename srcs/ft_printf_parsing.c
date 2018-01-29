/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:05:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:46:03 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_flags(const char **nav, t_conversion *result)
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

void			parse_minwidth(const char **nav, t_conversion *result)
{
	while (ft_isdigit(**nav))
	{
		result->min_width = (result->min_width * 10) + (**nav - '0');
		(*nav)++;
	}
}

void			parse_precision(const char **nav, t_conversion *result)
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

void			parse_length(const char **nav, t_conversion *result)
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

void			parse_type(const char **nav, t_conversion *result)
{
	const char		types[] = TYPES;
	const char		*test = types;

	while (*test)
	{
		if (*test == **nav)
		{
			result->type = **nav;
			(*nav)++;
			break ;
		}
		test++;
	}
}
