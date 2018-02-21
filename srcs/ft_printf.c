/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:26:42 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 10:23:54 by mschneid    ###    #+. /#+    ###.fr     */
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

int				ft_printf_start(const char **nav, va_list ap, t_output *output)
{
	t_conversion	*actual;

	actual = printf_parsing(nav, ap, output);
	printf_process_type(actual);
	if (actual->size == -1)
	{
		free(actual);
		return (-1);
	}
	ft_strstructjoin(actual, output);
	output->lastgood = output->size;
	free(actual->output);
	free(actual);
	return (0);
}

int				ft_printf_return(t_output *output, int stop)
{
	write(1, output->output, output->lastgood);
	free(output->output);
	if (stop)
		output->size = -1;
	return (output->size);
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
	output.lastgood = 0;
	va_start(ap, format);
	while (*nav)
	{
		if (*nav == '%')
		{
			if ((stop = ft_printf_start(&nav, ap, &output)))
				break ;
		}
		else
			ft_outputaddchar(&output, (*(nav++)));
	}
	if (!*nav)
		output.lastgood = output.size;
	va_end(ap);
	return (ft_printf_return(&output, stop));
}
