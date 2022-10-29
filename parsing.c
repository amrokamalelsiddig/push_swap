/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:52:40 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/29 13:20:48 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **a, int val)
{
	t_stack	*tmp;

	if ((*a) == NULL)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = val;
		tmp->next = NULL;
		tmp->index = -1;
		*a = tmp;
	}
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->index = -1;
		tmp->data = val;
		ft_lstadd_back(a, tmp);
	}
}
