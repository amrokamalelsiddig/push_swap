/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:52:40 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/13 19:04:16 by aelsiddi         ###   ########.fr       */
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

int	all_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while ((str[i][j] < 48) || (str[i][j] > 57))
			return (0);
		j++;
	i++;
	}	
	return (1);
}

int	fdup(t_stack **a, int val, t_push_swap *ps)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp)
	{
		if (tmp->data == val)
			exit_error(2, ps);
		tmp = tmp->next;
	}	
	return (1);
}
