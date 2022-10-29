/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:21:44 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/29 18:55:02 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->data > s->next->data)
		{
			return (0);
		}
		s = s->next;
	}
	return (1);
}

int	space_locate(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_atoi(char *str, t_push_swap *ps)
{
	int 	res;
	int		sign;
	int 	i;

	i		= 0;
	res		= 0;
	sign	= 1;
	while (str[i] == ' '  || str[i]== '\t' || str[i]== '\n'\
		|| str[i] == '\v' || str[i]== '\f' || str[i]== '\r')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
		{
			exit_error(1, ps);
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		exit_error(2, ps);
	if (res * sign >= MAX_INT || res * sign <= MIN_INT)
		exit_error(2, ps);
	return (res * sign);
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
		{
			printf("is char %c\n",str[i][j]);
			return (0);
		}
		printf("is num : %c\n",str[i][j]);
		j++;
	i++;
	}	
	return (1);
}

int	find_duplicate(t_stack **a, int val, t_push_swap *ps)
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
