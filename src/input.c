/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:58 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/06 19:53:33 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* nb_str_cmp:
*   Controlla se due stringhe di numeri siano uguali.
*   Se una stringa inizia per '+' allora viene ignorato e il resto della stringa
*   di numeri viene controllata.
*   In modo tale che: +123 == 123 ma -123 != 123.
*   Returna 0 se le stringhe sono uguali, un altro valore se non lo sono.
*/
int	nb_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

/* is_number:
*   Controlla se l'input inserito è un numero. +1 1 e -1 sono considerati validi.
*   Returna 1 se l'input è un numero, 0 se non lo è.
*/
static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (segno(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* doppie:
*   Controlla se la lista ha della doppie.
*   Returna 1 se le ha, 0 se non le ha.
*/
static int	doppie(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nb_str_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* zero:
*   Controlla che l'argomento sia 0 per evitare: 0 +0 -0 0 0000 +000 -00000000.
*   Returna 1 se l'argomento è zero, 0 se contiene più di uno 0.
*/
static int	zero(char *argv)
{
	int	i;

	i = 0;
	if (segno(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* input_check:
*   Controlla se l'input è composto da soli numeri senza ripetizioni.
*   Returna 1 se l'input è corretto, 0 se è sbagliato.
*/
int	input_check(char **argv)
{
	int	i;
	int	zeri;

	zeri = 0;
	i = 1;
	while (argv[i])
	{
		zeri += zero(argv[i]);
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
	if (zeri > 1)
		return (0);
	if (doppie(argv))
		return (0);
	return (1);
}
