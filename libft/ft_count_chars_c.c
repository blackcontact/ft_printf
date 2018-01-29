/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_chars_c.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 13:43:08 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:02:36 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_chars_c(const char *str, char c)
{
	int		j;

	j = 0;
	while (!(*str == c) && *str)
	{
		str++;
		j++;
	}
	return (j);
}
