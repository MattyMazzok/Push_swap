/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:28:40 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/05 22:10:56 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
*	Assegna ad ogni elemento della stack a una posizione dall'inizio alla
*	fine della stack in ordine crescente
*	Questo valore viene poi usato per calcolare il costo di spostare un numero
*	in una certa posizione.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
*	Fornisce la posizione attuale dell'elemnto con il valore più piccolo.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Sceglie il miglior target in base alla posizione nella stack a utilizzando
*	un indice di un elemento della stack b. Controlla se l'elemento della stack
*	b può essere posizionato tra gli elementi della stack a, controllando gli
*	indici degli elementi della stack a. Se non è possibile inserirlo tra gli
*	elemnti della stack a allora cerca l'elemento con l'indice più piccolo della
*	stack a e lo segna come miglior target.
*/
static int	get_target(t_stack **a, int b_inx, int target_inx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_inx && tmp_a->index < target_inx)
		{
			target_inx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_inx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_inx)
		{
			target_inx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
*	Assigns a target position in stack A to each element of stack A.
*	The target position is the spot the element in B needs to
*	get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to
*	its target position in stack A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
