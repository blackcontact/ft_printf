/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/16 17:27:13 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:03:20 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *temp2;

	temp2 = *alst;
	while (temp2)
	{
		temp = temp2->next;
		del(temp2->content, temp2->content_size);
		free(temp2);
		temp2 = temp;
	}
	*alst = NULL;
}
