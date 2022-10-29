/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:24:07 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/24 21:00:23 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_binary_count(t_stack **a)
{
	t_stack	*tmp;
	int		max_num;
	int		binary_count;

	binary_count = 0;
	tmp = (*a);
	max_num = tmp->index;
	while (tmp != NULL)
	{
		if (max_num < tmp->index)
			max_num = tmp->index;
		tmp = tmp->next;
	}
	while (max_num != 0)
	{
		max_num = max_num >> 1;
		binary_count++;
	}
	return (binary_count);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*lst;
	int		max_pos;
	int		i;
	int		j;
	int		size_a;

	max_pos = max_binary_count(a);
	i = 0;
	j = 0;
	while (max_pos > j)
	{
		i = -1;
		size_a = ft_lstsize(*a);
		while (++i < size_a)
		{
			lst = (*a);
			if (((lst->index >> j) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		j++;
		while (ft_lstsize(*b))
			pa(a, b);
	}
}

int	cost(t_stack **a, int val)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == val)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	handle_min5(t_stack **a, t_stack **b)
{
	int	min_loc;

	min_loc = cost(a, 1);
	if (min_loc == 2)
		sa(a);
	else if (!(min_loc == 1))
	{
		while ((*a)->index != 1)
			reverse_rotate(a);
	}
	pb(a, b);
}
