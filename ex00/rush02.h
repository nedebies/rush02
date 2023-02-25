/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:19:10 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/25 06:07:39 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h> // en
# include <sys/stat.h> // open
# include <sys/types.h> // open
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_dict
{
	int				nb;
	int				suffix;
	char			*literal;
	struct s_dict	*next;
}				t_dict;

char			**ft_split(char *str, char *charset);
char			*ft_strdup(char *src);
t_dict			*ft_list_push_strs(int size, char **strs);
t_dict			*ft_create_node(int n, int suffix, char *literal);
int				ft_lst_push(t_dict **liste, int n, int suffix, char *lit);
int				ft_file_read(char *filepath, t_dict **begin);
int				ft_simple_atoi(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				parse_dict(t_dict **begin, char *str);
int				ft_strlen(char *str);
int				check_number(char *nbr, t_dict *begin_list);
void			ft_lst_sort(t_dict **begin_list);
void			ft_lst_clear(t_dict **begin_with);
void			check_and(int nb, int i, char *nbr);
int				check_nb(int nb, t_dict *begin_list);
void			to_print(int nbr, t_dict *begin_list, int i, char *nbrc);
void			print_union(int i, char *nbr, int j, t_dict *begin_list);
int				check_length(char *nbr);

#endif
