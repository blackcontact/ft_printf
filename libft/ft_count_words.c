/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_words.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 11:48:34 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:02:49 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '	' || str[i] == '\n') && str[i])
			i++;
		if (str[i])
			words++;
		while (!(str[i] == ' ' || str[i] == '	' || str[i] == '\n') && str[i])
			i++;
	}
	return (words);
}
