/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:21:44 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/13 19:15:30 by aelsiddi         ###   ########.fr       */
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_init(int *i, int *s, long *n)
{
	*i = 0;
	*s = 1;
	*n = 0;
}

int	ft_atoi(char *str, t_push_swap *ps)
{
	long	res;
	int		sign;
	int		i;

	ft_init(&i, &sign, &res);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'\
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
			exit_error(1, ps);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		exit_error(2, ps);
	if (res * sign > MAX_INT || res * sign < MIN_INT)
		exit_error(2, ps);
	return (res * sign);
}

// int	ft_isspace(char c)
// {
// 	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
// 		|| c == '\v' || c == ' ')
// 		return (1);
// 	else
// 		return (0);
// }

// static void	ft_init(int *i,int *s, int *n)
// {
// 	*i = 0;
// 	*s = 1;
// 	*n = 0;
// }

// int	ft_atoi(char *str, t_push_swap *ps)
// {
// 	int		res;
// 	int		sign;
// 	int		i;

// 	ft_init(&i, &sign, &res);
// 	while (ft_isspace(str[i]))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
// 			exit_error(1, ps);
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	if (str[i])
// 		exit_error(2, ps);
// 	if (res * sign >= MAX_INT || res * sign <= MIN_INT)
// 		exit_error(2, ps);
// 	return (res * sign);
// }
