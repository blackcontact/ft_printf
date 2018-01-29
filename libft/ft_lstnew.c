/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/16 13:52:16 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:03:36 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*output;

	if (!(output = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		content = NULL;
	else
		output->content = ft_memalloc(content_size);
	if (output->content)
		ft_memcpy(output->content, content, content_size);
	if (content)
		output->content_size = content_size;
	else
		content_size = 0;
	output->next = NULL;
	return (output);
}
