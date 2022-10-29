/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:54:34 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/29 12:46:17 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *head)
{
	t_stack	*current_node;

	current_node = head;
	while (current_node != NULL)
	{
		printf("%d -> %d\n", current_node->data, current_node->index);
		current_node = current_node->next;
	}
}

void	free_nodes(t_stack *a, t_stack *b)
{
	t_stack	*current_node;
	t_stack	*next_node;
	t_stack	*current_node2;
	t_stack	*next_node2;

	current_node = a;
	next_node = NULL;
	current_node2 = b;
	next_node2 = NULL;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	while (current_node2 != NULL)
	{
		next_node2 = current_node2->next;
		free (current_node2);
		current_node2 = next_node2;
	}
}

void free_split(t_push_swap *ps)
{
	int i;

	i = 0;

	while (ps->split_array[i])
	{
		free(ps->split_array[i]);
		i++;
	}
	free(ps->split_array[i]);
}

void	ft_lstrangeup(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
}

void	exit_error(int i, t_push_swap *ps)
{
	if (i == 6)
	{
		free_split(ps);
		// free_nodes(ps->a, ps->b);
		write(1, "Error\n", 6);
	}
	else if(i == 1)
	{
		write(1, "Error\n", 6);
		// printf("atoi error\n\n"6;
		free(ps->split_array);
		exit(1);
	}
	else if(i == 2)
	{
		write(1, "Error\n", 6);
		// printf("atoi non num error\n\n"6;
		free_split(ps);
		exit(1);
	}
	else if(i == 5)
	{
		write(1, "Error\n", 6);
		// printf("duplicate error\n\n"6;
		free_nodes(ps->a, ps->b);
		free(ps->split_array);
		exit(1);
	}
	else if (i == 8)
	{
		// write(1, "Error\n", 6);
		free_split(ps);
		free_nodes(ps->a, ps->b);
	}
	return;
}

char	**whatever(char **result, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}