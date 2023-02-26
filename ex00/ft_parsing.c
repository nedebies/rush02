/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:39:47 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 12:14:53 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_exists(t_dict *begin, int nb)
{
	while (begin)
	{
		if (begin->nb == nb)
			return (0);
		begin = begin->next;
	}
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
	{
		if (str[i] != ' ')
			j++;
		else if (str[i - 1] != ' ')
			j++;
	}
	s = malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ' || str[i - 1] != ' ')
			s[j++] = str[i];
	s[j] = 0;
	return (s);
}

static int	check_line(char *str, int *i)
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

static int	parse_dict2(int nb, int idx, t_dict **dict, char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (idx == 0)
		if (check_exists(*dict, nb) == 0)
			return (0);
	i = 0;
	if (check_line(str, &i) == 0)
		return (0);
	s = ft_strdup(str + i);
	if (!s)
		return (0);
	s = ft_check_space(s);
	if (!s)
		return (0);
	if (ft_lst_push(dict, nb, idx, s) == 0)
		return (0);
	return (1);
}

int	parse_dict(t_dict **dict, char *str)
{
	int		nb;
	int		idx;

	if (get_nb(&nb, &idx, str) == 0)
		return (0);
	if (nb != 0)
		return (parse_dict2(nb, idx, dict, str));
	else if (ft_simple_atoi(str) != -1)
	{
		nb = ft_simple_atoi(str);
		return (parse_dict2(nb, idx, dict, str));
	}
	return (0);
}
