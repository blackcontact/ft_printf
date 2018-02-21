/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 15:10:12 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 10:25:07 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printf_process_modulo(t_conversion *actual)
{
	actual->output = ft_strdup("%");
	actual->size++;
	if (!actual->flags[2] && actual->flags[1]
		&& actual->min_width > actual->size)
	{
		ft_nbchar_bef('0', actual->min_width - actual->size, actual);
		actual->size += actual->min_width - actual->size;
	}
	ft_printf_output_align(actual);
}

static void		printf_process_unknown(t_conversion *actual)
{
	long	test;

	test = actual->type;
	actual->value = (void *)test;
	if (actual->type)
		printf_process_char(actual);
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
	else if (actual->type == 'n')
		printf_process_n(actual);
	else
		printf_process_unknown(actual);
}

void			ft_nbchar_bef(char c, int i, t_conversion *actual)
{
	char	*s1;
	char	*temp;
	int		j;
	int		k;

	s1 = ft_strnew(i);
	j = i;
	while (j--)
		s1[j] = c;
	temp = actual->output;
	actual->output = ft_strnew(i + actual->size);
	j = 0;
	while (j < i)
	{
		actual->output[j] = s1[j];
		j++;
	}
	k = 0;
	while (j < i + actual->size)
		actual->output[j++] = temp[k++];
	free(temp);
	free(s1);
}

void			ft_nbchar_aft(char c, int i, t_conversion *actual)
{
	char	*s1;
	char	*temp;
	int		j;
	int		k;

	s1 = ft_strnew(i);
	j = i;
	while (j--)
		s1[j] = c;
	temp = actual->output;
	actual->output = ft_strnew(i + actual->size);
	j = 0;
	while (j < actual->size)
	{
		actual->output[j] = temp[j];
		j++;
	}
	k = 0;
	while (j < i + actual->size)
		actual->output[j++] = s1[k++];
	free(temp);
	free(s1);
}
