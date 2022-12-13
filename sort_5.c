/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:56:33 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/13 19:16:02 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		min_loc;

	min_loc = 0;
	min = (*a)->data;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
		}
		tmp = tmp->next;
	}
	min_loc = cost(a, min);
	while ((*a)->data != min)
	{
		if (min_loc <= 3)
			ra(a);
		else
			reverse_rotate(a);
	}
	pb(a, b);
}
