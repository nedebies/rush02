/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:11:42 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/26 12:11:45 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_nb(int *nb, int *idx, char *str)
{
	int		i;
	int		j;

	i = 0;
	*nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i >= 4)
	{
		j = -1;
		if ((i - 1) % 3 != 0)
			return (0);
		while (++j < i)
			if ((j == 0 && str[j] != '1') || (j != 0 && str[j] != '0'))
				return (0);
		*nb = i / 3;
		*idx = 1;
	}
	else
		*idx = 0;
	return (1);
}

int	check_nb(int nb, t_dict *start)
{
	while (start->next != 0 && (start->idx == 1 || nb != start->nb))
		start = start->next;
	if (start->next == 0)
		return (0);
	return (1);
}
