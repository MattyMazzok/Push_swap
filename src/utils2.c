/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:18:20 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/05 15:37:25 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_stack_before_bottom:
*	Returna il penultimo elemento dela stack.
*/
t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
*	Ritorna il valore assoluto del numero dato in input.
*	Serve per calcolare la distanza dallo 0.
*/
int	nb_ass(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* free_stack:
*	Freea la stack fornita e imposta il puntatore alla stack a NULL.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
