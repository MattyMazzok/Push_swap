/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:25:07 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/05 22:27:02 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push:
*	Pusha il primo elemento della stack src in cima alla stack dest.
*/
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* pa:
*	Pusha il primo elemento della stack b in cima alla stack a.
*	Stampa "pa" nello standard output.
*/
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* pb:
*	Pusha il primo elemento della stack a in cima alla stack b.
*	Stampa "pb" nello standard output.
*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
