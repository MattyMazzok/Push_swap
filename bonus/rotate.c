/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:33:29 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/08 00:49:46 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_check(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	rb_check(t_stack **stack_b)
{
	rotate_check(stack_b);
}

void	ra_check(t_stack **stack_a)
{
	rotate_check(stack_a);
}

void	rr_check(t_stack **stack_a, t_stack **stack_b)
{
	rotate_check(stack_a);
	rotate_check(stack_b);
}
