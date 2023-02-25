/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:30:03 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:07:19 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_list_clear(t_dict **start)
{
	t_dict	*ptr;
	t_dict	*lst;

	lst = *start;
	if (lst)
		while (lst)
		{
			ptr = lst->next;
			free(lst->literal);
			free(lst);
			lst = ptr;
		}
}

int		ft_lst_push(t_dict **lst, int n, int suf, char *lit)
{
	t_dict	*push;

	if (lst)
	{
		push = ft_create_node(n, suf, lit);
		if (!push)
			return (0);
		push->next = *lst;
		*lst = push;
	}
	else
	{
		if (!(*lst = ft_create_node(n, suf, lit)))
			return (0);
	}
	return (1);
}
t_dict	*ft_create_node(int n, int suf, char *literal)
{
	t_dict	*node;

	node = NULL;
	node = malloc(sizeof(t_dict));
	if (!node)
		return (0);
	if (node)
	{
		node->nb = n;
		node->suf = suf;
		node->literal = malloc(sizeof(char) * (strlen(literal) + 1));
		if (!node->literal)
			return (0);
		node->literal = literal;
		node->next = NULL;
	}
	return (node);
}

static void	ft_lst_swap(t_dict *lst)
{
	int		nb;
	int		suf;
	char	*literal;

	nb = lst->nb;
	suf = lst->suf;
	literal = lst->literal;
	lst->nb = lst->next->nb;
	lst->suf = lst->next->suf;
	lst->literal = lst->next->literal;
	lst->next->nb = nb;
	lst->next->suf = suf;
	lst->next->literal = literal;
}

void	ft_lst_sort(t_dict **start)
{
	t_dict	*dict1;
	t_dict	*dict2;

	dict1 = *start;
	while (dict1)
	{
		dict2 = *start;
		while (dict2->next)
		{
			if (dict2->nb < dict2->next->nb)
				ft_lst_swap(dict2);
			dict2 = dict2->next;
		}
		dict1 = dict1->next;
	}
}