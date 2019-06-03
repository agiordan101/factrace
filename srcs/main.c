/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 14:21:38 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:57:33 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "factrace.h"

static int		append_str(char ***tab, char *str)
{
	char	**tmp;
	int		len;

	len = ft_tablen(*tab);
	if (!(tmp = (char **)malloc(sizeof(char *) * (len + 2))))
		return (-1);
	ft_tabcpy(*tab, tmp);
	free(*tab);
	tmp[len] = str;
	tmp[len + 1] = NULL;
	*tab = tmp;
	return (1);
}

static int		append_char(char **str, char c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str) + 2;
	if (!(tmp = malloc(sizeof(char) * len)))
		return (-1);
	ft_strcpy(*str, tmp);
	free(*str);
	tmp[len - 2] = c;
	tmp[len - 1] = '\0';
	*str = tmp;
	return (1);
}

static char		*read_number(void)
{
	char	*str;
	char	buff[1];

	str = NULL;
	while (read(0, buff, 1) > 0)
	{
		if (buff[0] == '\n' || !buff[0])
			return (str);
		if (!str)
		{
			if (!(str = malloc(sizeof(char) * 2)))
				return (NULL);
			str[0] = buff[0];
			str[1] = '\0';
		}
		else if (append_char(&str, buff[0]) == -1)
			return (NULL);
	}
	return (str);
}

static int		read_tab(char ***atab, int set_length)
{
	char	**tab;
	char	*nbr;
	int		index;

	tab = *atab;
	index = 0;
	while ((nbr = read_number()) && index < set_length)
	{
		append_str(atab, nbr);
		index++;
	}
	if (!nbr && index == 0)
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	char	**nbr_tab;
	t_prime	*first;
	int		last_find;
	int		last_index;
	int		set_length;
	int		i;

	nbr_tab = NULL;
	if (ac == 1 || !av)
		return (0);
	set_length = ft_atoi(av[1]) / 20 + 1;
	i = 1;
	last_find = -1;
	while (read_tab(&nbr_tab, set_length) == 1)
	{
		last_index = -1;
		algo_begin(nbr_tab + (i - 1) * set_length, &last_index);
		if (last_index != -1)
			last_find = (i - 1) * set_length + last_index;
		i++;
	}
	last_find++;
	if (!(first = (t_prime *)malloc(sizeof(t_prime))))
		return (1);
	mpz_init_set_d(first->prime, 691);
	first->next = NULL;
	algo(nbr_tab + last_find, first);
	return (0);
}

