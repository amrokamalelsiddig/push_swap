/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:57:59 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/24 20:57:54 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	reverse_rotate(t_stack**a)
{
	t_stack	*holder;
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	holder = tmp->next;
	holder->next = (*a);
	tmp->next = NULL;
	(*a) = holder;
	write(1, "rra\n", 4);
}

void	ra(t_stack **a)
{
	ft_lstrangeup(a);
	write(1, "ra\n", 3);
}
