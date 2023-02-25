/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:39:47 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:08:10 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		check_exists(t_dict *begin, int nb)
{
	while (begin)
	{
		if (begin->nb == nb)
			return (0);
		begin = begin->next;
	}
	return (1);
}

int		get_nb(int *nb, int *idx, char *str)
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

char	*ft_check_space(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ')
			j++;
		else if (str[i - 1] != ' ')
			j++;
	if ((s = malloc(sizeof(char) * (j + 1))) == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ' || str[i - 1] != ' ')
			s[j++] = str[i];
	s[j] = 0;
	return (s);
}

static int		check_line(char *str, int *i)
{
	int		j;

	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != ':')
		return (0);
	(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	j = *i;
	while (str[++j])
		if (str[j] <= 31 || str[j] >= 127)
			return (0);
	return (1);
}

int		parse_dict(t_dict **begin, char *str)
{
	int		nb;
	int		i;
	int		idx;
	char	*s;

	if (get_nb(&nb, &idx, str) == 0)
		return (0);
	if (nb != 0 || (nb = ft_simple_atoi(str)) != -1)
	{
		if (idx == 0)
			if (check_exists(*begin, nb) == 0)
				return (0);
		i = 0;
		if (check_line(str, &i) == 0)
			return (0);
		if ((s = ft_strdup((str + i))) == NULL)
			return (0);
		if ((s = ft_check_space(s)) == NULL)
			return (0);
		if (ft_lst_push(begin, nb, idx, s) == 0)
			return (0);
		return (1);
	}
	return (0);
}
