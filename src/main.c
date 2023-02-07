/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:28:59 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/07 17:33:08 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* find_highest_index:
*	Ritorna l'indice più grande nella stack-
*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
*	Ordina una stack di 3 numeri in base agli indici in 2 mosse.
*/
void	tiny_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

/* is_sorted:
*	Controlla se la stack è gia ordinata.
*	Ritorna 0 se è ordinata, 1 se non lo è,
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Sceglie il metodo di sorting in base alla lughezza della stack.
*	Se la stack è lunga 2 e non è ordinata swappa i due valori.
*	Se la stack è lunga 3 allora fa un semplice tiny sort.
*	Se la stack è più lunga di tre utilizza un algoritmo di sorting.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	Controlla l'input, se corretto inizializza la stack a e b, inserisce poi
*	ogni valore nella stack a e inizializza la stack b a Null per poi aggiungere
*	degli indici ai valori nella stack a, chiama la funzione push_swap per sortare
*	la stack infine free a entrambe le stack.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		stack_size;
	int		size;

	size = 0;
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
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
