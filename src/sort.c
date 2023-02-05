/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:20:25 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/05 22:11:54 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* shift_stack:
*	Dopo che il grosso del sorting è stato completato ruota la stack in modo
*	che l'elemneto più piccolo sia in cima. Se l'elemento si strova nella
*	seconda metà della stack allora farea un reverse rotate.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

/* do_cheapest_move:
*	Trova l'elemento della stack b con il costo minore e poi lo sposta nella
*	stack a nella posizione correta.
*/
void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_ass(tmp->cost_a) + nb_ass(tmp->cost_b) < nb_ass(cheapest))
		{
			cheapest = nb_ass(tmp->cost_b) + nb_ass(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}

/* get_cost:
*	Calcola il costo (in mosse) di muovere ogni elemento della stack b nella
*	posizione corretta nella stack a.
*	Se l'elemento si trova nella prima metà della stack il costo sarà positivo,
*	se invece l'elemento è nella seconda metà il costo sarà negativo.
*	Vengono calcolati:
*	-cost_b che rappresenta il costo di spostare un elemento in cima alla stack b
*	-cost_a che rappresenta il costo di arrivare alla giusta posizione
*		nella stack a
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/* push_all_save_three:
*	Pusha dalla stack a alla stack b tutti gli elemnti tranne gli ultimi tre.
*	Vengono pushati prima i numeri più piccolu e poi quelli più grandi per
*	migliorere la efficacia del sorting.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/* sort:
*	Pusha tutto tranne 3 numeri dalla stack a nella stack b
*	sorta poi i 3 numeri rimasti nella stack a e calcolandosi la migliore mossa
*	da fare shifta gli elementi nella stack a in ordine.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
