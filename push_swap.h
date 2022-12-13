/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:08:02 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/13 19:07:33 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct push_swap
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	int		atoi_sign;
	int		atoi_res;
	int		atoi_i;
	int		main_i;
	int		mn_j;
	char	**sp_ar;
	int		arguments;
	int		index;
}	t_push_swap;

//*************helpers.c************************//
int		ft_strlen(char *str);
int		check_space(char **str);
void	print(t_stack *head);
void	free_nodes(t_stack *a, t_stack *b);
void	ft_lstrangeup(t_stack **a);
void	exit_error(int i, t_push_swap *ps);
//*************indexing************************//
void	indexing(t_stack **a, int i);
void	ft_lstiter(t_stack *lst, void (*f)(void *));
void	ft_lstdelone(t_stack	*lst, void (*del)(void *));

//***************linked_list.c*******************//
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
void	ft_lstadd_front(t_stack	**alst, t_stack	*new);
int		ft_lstsize(t_stack	*lst);
void	ft_lstclear(t_stack **lst, void (*del)(void*));

//***************operations.c*******************//
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack**a);
void	ra(t_stack **a);

//***************operations2.c*******************//
void	fill_stack(t_stack **a, int val);

//***************sorting_A.c*******************//
int		all_number(char **str);
void	fill_it(int ac, char **av, t_stack **a);
void	arg_handler(int ac, t_stack **a, t_stack **b);

//***************sorting_B.c*******************//
int		max_binary_count(t_stack **a);
void	radix_sort(t_stack **a, t_stack **b);
int		cost(t_stack **a, int val);
void	handle_min5(t_stack **a, t_stack **b);
void	handle_max5(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
int		is_sorted(t_stack *s);
int		space_locate(char *str);
int		arg_count(int ac, char **av);
int		ft_isspace(char str);
int		ft_atoi(char *str, t_push_swap *ps);
int		all_num(char **str);
int		fdup(t_stack **a, int val, t_push_swap *ps);
void	free_split(t_push_swap *ps);
char	**ft_split(const char *str, char c);
void	pb_min(t_stack **a, t_stack **b);
void	pb_max(t_stack **a, t_stack **b);
#endif