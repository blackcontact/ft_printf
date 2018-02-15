/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:26:42 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 16:20:24 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_outputaddchar(t_output *o, char c)
{
	char		*output;
	int			i;

	if (!(output = (char *)malloc(sizeof(char) * (o->size + 1))))
		return ;
	i = 0;
	while (i < o->size)
	{
		output[i] = o->output[i];
		i++;
	}
	output[i] = c;
	free(o->output);
	o->output = output;
	o->size++;
}

void			ft_strstructjoin(t_conversion *a, t_output *o)
{
	char		*output;
	int			i;
	int			j;

	if (!(output = (char *)malloc(sizeof(char) * (a->size + o->size))))
		return ;
	i = 0;
	while (i < o->size)
	{
		output[i] = o->output[i];
		i++;
	}
	j = 0;
	while (j < a->size)
	{
		output[i + j] = a->output[j];
		j++;
	}
	o->size += a->size;
	free(o->output);
	o->output = output;
}

void			printf_process_type(t_conversion *actual)
{
	if (actual->type == 'd' || actual->type == 'i' || actual->type == 'D')
		printf_process_decimal(actual);
	else if (actual->type == 'u' || actual->type == 'U')
		printf_process_u_decimal(actual);
	else if (actual->type == '%')
		printf_process_modulo(actual);
	else if (actual->type == 'c' || actual->type == 'C')
		printf_process_char(actual);
	else if (actual->type == 'x' || actual->type == 'X')
		printf_process_hex(actual);
	else if (actual->type == 'o' || actual->type == 'O')
		printf_process_oct(actual);
	else if (actual->type == 'S' || (actual->type == 's'
	&& actual->length == 'l'))
		printf_process_wstring(actual);
	else if (actual->type == 's')
		printf_process_string(actual);
	else if (actual->type == 'p')
		printf_process_pointer(actual);
	else
		printf_process_unknown(actual);
}

int				ft_printf_start(const char **nav, va_list ap, t_output *output)
{
	t_conversion	*actual;

	actual = printf_parsing(nav, ap);
	printf_process_type(actual);
	if (actual->size == -1)
	{
		free(actual);
		return (-1);
	}
	printf("VALUE = %d\n", (int)actual->value);
	ft_strstructjoin(actual, output);
	free(actual->output);
	free(actual);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	const char		*nav = format;
	t_output		output;
	int				stop;

	stop = 0;
	output.size = 0;
	output.output = ft_strnew(0);
	va_start(ap, format);
	while (*nav)
	{
		if (*nav == '%')
		{
			if (!*(nav + 1))
				break ;
			if ((stop = ft_printf_start(&nav, ap, &output)))
				break ;
		}
		else
			ft_outputaddchar(&output, (*(nav++)));
	}
	va_end(ap);
	if (stop)
		output.size = -1;
	else
		write(1, output.output, output.size);
	free(output.output);
	return (output.size);
}
