/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:52:55 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/07 23:11:49 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* swap:
*	Scambia le posizioni dei primi due elementi di una stack.
*	Se la stack non ha almeno due elementi allora non fa nulla.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* sa:
*	Scambia i primi due elemnti della stack a.
*	Stampa "sa" nello standard output.
*/
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* sb:
*	Scambia i primi due elemnti della stack b.
*	Stampa "sb" nello standard output.
*/
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* ss:
*	Scambia i primi due elementi della stack a e i primi due elementi della stack b
*	Prints "ss" to the standard output.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
