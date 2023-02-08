/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:33:52 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/08 00:49:59 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate_check(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rrr_check(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_check(stack_a);
	rev_rotate_check(stack_b);
}

void	rrb_check(t_stack **stack_b)
{
	rev_rotate_check(stack_b);
}

void	rra_check(t_stack **stack_a)
{
	rev_rotate_check(stack_a);
}
