/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:45:16 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/05 22:09:54 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rotate:
*	L'ultimo elemento di una stack viene spostato in cima.
*/
static void	rev_rotate(t_stack **stack)
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

/* rrr:
*	Sposta gli ultimi elemnti della stack a e b in cima alle rispettive stack.
*   Stampa "rrr" nello standard output.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}

/* rrb:
*	Sposta l'ultimo elemento della stack b in cima.
*	Stampa "rrb" nello standard output.
*/
void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* rra:
*	Sposta l'ultimo elemento della stack a in cima.
*	Stampa "rra" nello standard output.
*/
void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}
