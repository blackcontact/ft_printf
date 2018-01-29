/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_whitespaces.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 11:46:54 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:04:45 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_whitespaces(char *str)
{
	int		words;
	int		i;
	int		i_words;
	char	**output;

	words = ft_count_words(str);
	if (!(output = (char **)malloc(sizeof(char *) * words)))
		return (NULL);
	i_words = 0;
	while (i_words < words)
	{
		while ((*str == ' ' || *str == '	' || *str == '\n') && (*str))
			str++;
		if (!(output[i_words] = (char *)
		malloc(sizeof(char) * ft_count_chars(str))))
			return (NULL);
		i = ft_count_chars(str);
		output[i_words] = ft_strncpy(output[i_words], str, i);
		output[i_words][i] = '\0';
		str = str + i;
		i_words++;
	}
	return (output);
}
