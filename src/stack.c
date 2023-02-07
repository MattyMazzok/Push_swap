/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:05:29 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/06 19:53:45 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* get_stack_size:
*	Ritorna il numero di elementi nella stack fornita.
*/
int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/* get_stack_bottom:
*	Ritorna l'ultimo elekmento della stack fornita.
*/
t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* add_stack_bottom:
*	Aggiunge un elemento alla fine della stack fornita.
*/
void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

/* stack_new:
*	Crea un nuovo nodo nella lista con i dati forniti,
*   ritorna l'elemento appena creato.
*/
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* fill_stack_values:
*	Riempie la stack a con i dati forniti e se un valore è superiore al max
*   int stampa un errore e trmina il programma.
*/
t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
