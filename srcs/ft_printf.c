/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:26:42 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:46:37 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_process_type(t_conversion *actual)
{
	if (actual->type == 'd' || actual->type == 'i' || actual->type == 'D')
		return (printf_process_decimal(actual));
	else if (actual->type == 'u' || actual->type == 'U')
		return (printf_process_u_decimal(actual));
	else if (actual->type == '%')
		return (printf_process_modulo(actual));
	else if (actual->type == 'c' || actual->type == 'C')
		return (printf_process_char(actual));
	else if (actual->type == 'x' || actual->type == 'X')
		return (printf_process_hex(actual));
	else if (actual->type == 'o' || actual->type == 'O')
		return (printf_process_oct(actual));
	else if (actual->type == 's' || actual->type == 'S')
		return (printf_process_string(actual));
	return (0);
}

int				ft_printf_start(const char **nav, va_list ap)
{
	t_conversion	*actual;
	int				ret;

	actual = printf_parsing(nav, ap);
	if (!actual)
		return (0);
	ret = printf_process_type(actual);
	free(actual->output);
	free(actual);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	const char		*nav = format;
	int				count;

	count = 0;
	va_start(ap, format);
	while (*nav)
	{
		if (*nav == '%')
		{
			if (!*(nav + 1))
				return (count);
			count += ft_printf_start(&nav, ap);
		}
		else
		{
			ft_putchar(*(nav++));
			count++;
		}
	}
	va_end(ap);
	return (count);
}
