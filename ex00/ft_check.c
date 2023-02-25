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

static int		check_suff(int j, t_dict *begin_list)
{
	while (begin_list->next != 0
		&& (begin_list->suf == 0 || j != begin_list->nb))
		begin_list = begin_list->next;
	if (begin_list->next == 0)
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
	char	nbr2[4];

	k = 0;
	while (nbr[*i] == '0')
		(*i)++;
	if (*j % 3 != 0)
	{
		while (*j % 3 != 0 || *j == 0)
		{
			nbr2[k++] = nbr[(*i)++];
			(*j)--;
		}
		nbr2[k] = 0;
		send_to_print((nb = ft_simple_atoi(nbr2)), start, *i, nbr);
		if (*j == 0)
		{
			ft_putchar('\n');
			return (0);
		}
		if (*j >= 3)
			print_suff(*i, nbr, *j / 3, start);
	}
	return (1);
}

void	make_three(int i, int j, char *nbr, t_dict *start)
{
	int		nb;
	int		k;
	char	nbr2[4];

	while (j > 0)
	{
		k = 0;
		while (k != 3)
		{
			nbr2[k] = nbr[i];
			i++;
			j--;
			k++;
		}
		nbr2[k] = 0;
		nb = ft_simple_atoi(nbr2);
		if (nb != 0)
		{
			send_to_print(nb, start, i, nbr);
			if (j >= 3)
				print_suff(i, nbr, j / 3, start);
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
	if (j > 3 && check_suff((j - 1) / 3, start) == 0)
		return (0);
	if (ft_simple_atoi(nbr) == 0)
	{
		ft_putstr("zero");
		ft_putchar('\n');
		return (0);
	}
	if (first_check(nbr, &i, &j, start) == 0)
		return (0);
	make_three(i, j, nbr, start);
	ft_putchar('\n');
	return (0);
}
