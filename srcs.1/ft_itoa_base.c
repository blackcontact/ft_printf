/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:22:55 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 11:11:43 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long n, int base)
{
	static char			list[] = "0123456789abcdef";
	unsigned long long	temp;
	char				digits;
	char				neg;
	char				*output;

	neg = (n < 0 && base == 10 ? 1 : 0);
	temp = n < 0 ? -n : n;
	digits = 1;
	while (temp /= base)
		digits++;
	output = ft_strnew(digits + neg);
	temp = n < 0 ? -n : n;
	while (digits--)
	{
		output[digits + neg] = list[temp % base];
		temp /= base;
	}
	output[0] = neg ? '-' : output[0];
	return (output);
}

char	*ft_uitoa_base(unsigned long long n, int base)
{
	static char			list[] = "0123456789abcdef";
	unsigned long long	temp;
	int					digits;
	char				*output;

	temp = n;
	digits = 1;
	while (temp /= base)
		digits++;
	output = ft_strnew(digits);
	temp = n;
	while (digits--)
	{
		output[digits] = list[temp % base];
		temp /= base;
	}
	return (output);
}
