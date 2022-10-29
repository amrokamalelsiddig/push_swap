/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:00:28 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/29 17:11:53 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_max5(t_stack **a, t_stack **b)
{
	int	max_loc;

	max_loc = cost(a, ft_lstsize((*a)));
	if (!(max_loc == 1))
	{
		if (max_loc > 3)
		{
			while ((*a)->index < ft_lstsize((*a)))
				reverse_rotate(a);
		}
		else
		{
			while ((*a)->index > ft_lstsize((*a)))
				ra(a);
		}
	}
	pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	handle_max5(a, b);
	handle_min5(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	ra(a);
}

void	sort_three(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data && \
	(*a)->next->data < (*a)->next->next->data)
		sa(a);
	else if ((*a)->data > (*a)->next->data && (*a)->data > \
		(*a)->next->next->data && (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		reverse_rotate(a);
	}
	else if ((*a)->data > (*a)->next->data && (*a)->data > \
		(*a)->next->next->data && (*a)->next->data < (*a)->next->next->data)
		ra(a);
	else if ((*a)->data < (*a)->next->data && (*a)->data < \
			(*a)->next->next->data && (*a)->next->data > (*a)->next->next->data)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->data < (*a)->next->data && (*a)->data > \
		(*a)->next->next->data && (*a)->next->data > (*a)->next->next->data)
		reverse_rotate(a);
}
