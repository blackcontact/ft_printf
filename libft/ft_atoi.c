/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/08 18:37:49 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:01:54 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	size_t	i;
	int		minus;
	size_t	output;

	i = 0;
	output = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	if (minus)
		output = -output;
	return (output);
}
