/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:17:13 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/08 01:58:34 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_error_check(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	rrr_or_error(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		rra_check(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		rrb_check(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		rrr_check(stack_a, stack_b);
	else
		exit_error_check(NULL, NULL);
}

void	exec_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "\n"))
			return ;
		if (ft_strcmp(str, "sa\n"))
			sa_check(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			sb_check(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ss_check(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			pa_check(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			pb_check(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			ra_check(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			rb_check(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			rr_check(stack_a, stack_b);
		else
			rrr_or_error(stack_a, stack_b, str);
		str = ft_get_next_line(0);
	}
}

void	check_sort(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > (stack_a->next)->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	char	*str;

	tmp = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		stack_a = stack_check(argc, tmp, argv, 0);
	}
	else
	{
		stack_a = stack_check(argc, tmp, argv, 1);
	}
	stack_b = NULL;
	str = ft_get_next_line(0);
	exec_sort(&stack_a, &stack_b, str);
	check_sort(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
