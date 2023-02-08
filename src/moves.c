/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:25:30 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/07 23:11:35 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* rev_rotate_both:
*	Ruota entrambe le stack al contrario finchè una delle due è in posizione
*	(ovvero il costo è arrivato a 0).
*/
static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/* rotate_both:
*	Ruota entrambe le stack finchè una delle due è in posizione (ovvero il costo
*	è arrivato a 0).
*/
static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/* rotate_a:
*	Ruota la stack a finchè non è nella posizione correta.
*	Se la posizione data in input è positiva (prima metà della stack) allora
*	ruoterà la stack normalmente ma se invece la posizione è negativa (seconda
*	metà della stack) allora farà un reverse rotate.
*/
static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/* rotate_b:
*	Ruota la stack b finchè non è nella posizione correta.
*	Se la posizione data in input è positiva (prima metà della stack) allora
*	ruoterà la stack normalmente ma se invece la posizione è negativa (seconda
*	metà della stack) allora farà un reverse rotate.
*/
static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/* move:
*	Sceglie quale mossa fare per portare l'elemento della stack b nella
*	posizione corretta nella stack a.
*	In caso i costi sia della posizione a che quella di b allora le due stack
*	si muoveranno simultaneamente, risparmiando mosse.
*/
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
