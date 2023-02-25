/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:20:04 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:13:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int		ft_get_val(int ac, char **av, char **nb, char **path)
{
	if (ac == 2)
	{
		*path = "./numbers.dict";
		*nb = av[1];
		return (1);
	}
	else if (ac == 3)
	{
		*path = av[1];
		*nb = av[2];
		return (1);
	}
	return (0);
}

static int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_dict	*dict;
	char	*nb;
	char	*path;


	if (ft_get_val(ac, av, &nb, &path) == 0 || ft_str_is_numeric(nb) == 0)
		write(1, "Error\n", 6);
	else
	{
		dict = 0;
		if (ft_file_read(path, &dict) == 1)
			check_number(nb, dict);
		else
			write(1, "Dict Error\n", 12);
	ft_lst_clear(&dict);
	return (0);
}
