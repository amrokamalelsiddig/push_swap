/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:11:58 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/06 23:54:06 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

void	ft_lstadd_front(t_stack	**alst, t_stack	*new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
	ft_lstlast(*alst)->next = NULL;
}

int	ft_lstsize(t_stack	*lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	lst = 0;
}
