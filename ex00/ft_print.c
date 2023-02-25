/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:38:25 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:03:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_nb(int nb, t_dict *start)
{
	while (start->suffix == 1 || nb != start->nb)
		start = start->next;
	ft_putstr(start->literal);
	if (nb < 20 || nb > 99)
		write(1, " ", 1);
}

void	print_union(int i, char *nbr, int j, t_dict *start)
{
	while (start->suffix == 0 || j != start->nb)
		start = start->next;
	ft_putstr(start->literal);
	while (nbr[i] == '0')
		i++;
	if (nbr[i] != 0 && i != (check_length(nbr) - 1) && i != check_length(nbr) - 2)
		write(1, " ", 1);
	if (i == (check_length(nbr) - 1) || i == (check_length(nbr) - 2))
		write(1, " ", 1);
}

void	print_spaces(int nbr, t_dict *start)
{
	int		nb;

	if ((nbr % 100) >= 20)
	{
		print_nb((nb = (nbr % 100) - (nbr % 10)), start);
		if (nbr % 10 != 0)
		{
			nb = nbr % 10;
			write(1, " ", 1);
			print_nb(nb, start);
		}
	}
	else if ((nbr % 100) < 20 && (nbr % 100 != 0))
	{
		print_nb((nb = nbr % 100), start);
	}
}

void	print_hundreds(int nbr, t_dict *start)
{
	int		nb;

	if ((nbr / 100) > 0)
	{
		nb = nbr / 100;
		print_nb(nb, start);
		print_nb(100, start);
	}
	if (check_nb(nbr % 100, start) == 1)
	{
		print_nb(nbr % 100, start);
		if ((nbr % 100) >= 20)
			write(1, " ", 1);
	}
	else
		print_spaces(nbr, start);
}

void	to_print(int nbr, t_dict *start)
{
	int nb;

	nb = nbr;
	if (check_nb(nb, start) == 1)
	{
		if (nb == 100)
			write(1, "one ", 4);
		print_nb(nb, start);
		if (nb >= 20 && nb <= 99)
			write(1, " ", 1);
	}
	else
		print_hundreds(nbr, start);
}
