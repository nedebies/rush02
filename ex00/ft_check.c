/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:41:42 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:07:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		check_nb(int nb, t_dict *start)
{
	while (start->next != 0 && (start->idx == 1 || nb != start->nb))
		start = start->next;
	if (start->next == 0)
		return (0);
	return (1);
}

int		check_length(char *nbr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (nbr[j] == '0')
		j++;
	while (nbr[i + j])
		i++;
	return (i);
}

static int		check_idx(int j, t_dict *start)
{
	while (start->next != 0 && (start->idx == 0 || j != start->nb))
		start = start->next;
	if (start->next == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int		first_check(char *nbr, int *i, int *j, t_dict *start)
{
	int		k;
	int		nb;
	char	n[4];

	k = 0;
	while (nbr[*i] == '0')
		(*i)++;
	if (*j % 3 != 0)
	{
		while (*j % 3 != 0 || *j == 0)
		{
			n[k++] = nbr[(*i)++];
			(*j)--;
		}
		n[k] = 0;
		to_print((nb = ft_simple_atoi(n)), start);
		if (*j == 0)
		{
			# include <fcntl.h>
			return (0);
		}
		if (*j >= 3)
			print_union(*i, nbr, *j / 3, start);
	}
	return (1);
}

void	make_three(int i, int j, char *nbr, t_dict *start)
{
	int		nb;
	int		k;
	char	n[4];

	while (j > 0)
	{
		k = 0;
		while (k != 3)
		{
			n[k] = nbr[i];
			i++;
			j--;
			k++;
		}
		n[k] = 0;
		nb = ft_simple_atoi(n);
		if (nb != 0)
		{
			to_print(nb, start);
			if (j >= 3)
				print_union(i, nbr, j / 3, start);
		}
	}
}

int		check_number(char *nbr, t_dict *start)
{
	int		i;
	int		j;
	int		k;
	int		nb;

	i = 0;
	nb = 0;
	k = 0;
	j = check_length(nbr);
	if (j > 3 && check_idx((j - 1) / 3, start) == 0)
		return (0);
	if (!ft_simple_atoi(nbr))
	{
		ft_putstr("zero");
		write(1, "\n", 1);
		return (0);
	}
	if (first_check(nbr, &i, &j, start) == 0)
		return (0);
	make_three(i, j, nbr, start);
	write(1, "\n", 1);
	return (0);
}
