/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:51:10 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/24 21:01:05 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		min;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			min = tmp->data;
			tmp2 = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (min > tmp->data && tmp->index == -1)
		{
			min = tmp->data;
			tmp2 = tmp;
		}
		tmp = tmp->next;
	}
	tmp2->index = i;
}

void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->next);
		lst = lst->next;
	}
}

void	ft_lstdelone(t_stack	*lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->next);
	free(lst);
}
