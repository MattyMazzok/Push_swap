/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:34:08 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/08 01:16:28 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_check(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa_check(t_stack **stack_a)
{
	swap_check(*stack_a);
}

void	sb_check(t_stack **stack_b)
{
	swap_check(*stack_b);
}

void	ss_check(t_stack **stack_a, t_stack **stack_b)
{
	swap_check(*stack_a);
	swap_check(*stack_b);
}
