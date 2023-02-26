/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:37:12 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/26 12:23:53 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*ft_addchar(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = buf[0];
	new[i + 1] = 0;
	free(str);
	return (new);
}

static int	ft_buffer(int file, t_dict **begin, char *str, char *buf)
{
	while ((read(file, buf, 1)) != 0)
	{
		if (buf[0] != '\n')
		{
			str = ft_addchar(str, buf);
			if (!str)
				return (0);
		}
		else
		{
			if (parse_dict(begin, str) == 1)
			{
				free(str);
				str = malloc(sizeof(char));
				str[0] = 0;
			}
			else if (ft_strlen(str) != 0)
				return (0);
		}
	}
	ft_lst_sort(begin);
	return (1);
}

int	ft_file_read(char *filepath, t_dict **begin)
{
	int		file;
	char	*str;
	char	buf[1];

	str = malloc(sizeof(char));
	if (!str)
		return (0);
	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		if (ft_buffer(file, begin, str, buf) == 0)
			return (-1);
		return (1);
	}
	return (0);
}
