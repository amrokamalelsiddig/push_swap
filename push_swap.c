/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:07:48 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/29 18:38:03 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_it(int ac, char **str, t_stack **a)
{
	int		i;
	int		z;

	i = 0;
	while (str[i])
	{
		fill_stack(a, atoi(str[i]));
		i++;
	}
	z = 1;
	while (z < ac)
		indexing(a, z++);
}

void	arg_handler(int ac, t_stack **a, t_stack **b)
{
	if (is_sorted((*a)))
		return ;
	if (ac < 2)
		exit(1);
	else if (ac == 3)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		else
			return ;
	}
	else if (ac == 4)
		sort_three(a);
	else if (ac == 6)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

void	struct_init(t_push_swap *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->atoi_i = 0;
	ps->atoi_res = 0;
	ps->atoi_sign = 0;	
	ps->main_i = 1;
	ps->main_j = 0;
	ps->split_array = NULL;
	ps->arguments = 0;
	ps->index = 1;
}

int	main(int ac, char **av)
{
	t_push_swap	ps;

	struct_init(&ps);
	while (av[ps.main_i] != NULL)
	{
		ps.split_array = ft_split(av[ps.main_i], ' ');
		ps.main_j = 0;
		while (ps.split_array[ps.main_j])
		{
			if (!(find_duplicate(&ps.a, \
			ft_atoi(ps.split_array[ps.main_j], &ps), &ps)))
				exit_error(6, &ps);
			fill_stack(&ps.a, ft_atoi(ps.split_array[ps.main_j] ,&ps));
			ps.arguments++;
			ps.main_j++;
		}
		free_split(&ps);
		ps.main_i++;
	}
	ac = ps.arguments + 1;
	while (ps.index <= ac)
		indexing(&ps.a, ps.index++);
	arg_handler(ac, &ps.a, &ps.b);
	free_nodes(ps.a ,ps.b);
	return (0);
}

//ARG='80 505 60 20 10 "5 44"'; ./push_swap $ARG
// /./push_swap 80 505 60 20 10 "5 44"