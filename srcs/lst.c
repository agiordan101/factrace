/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 14:48:28 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:05:33 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "factrace.h"

int			ft_add_mpz_t(t_prime **last, mpz_t prime)
{
	t_prime	*new;

	if (!(new = (t_prime *)malloc(sizeof(t_prime))))
		return (0);
	mpz_init_set(new->prime, prime);
	new->next = NULL;
	(*last)->next = new;
	*last = new;
	return (1);
}

static void	del_prime(t_prime **first)
{
	t_prime	*lst;
	t_prime	*tmp;

	lst = *first;
	while (lst)
	{
		tmp = lst->next;
		mpz_clear(lst->prime);
		free(lst);
		lst = tmp;
	}
	*first = NULL;
}

int			clear_memory(int **tab, t_prime **first)
{
	if (*tab)
	{
		free(*tab);
		*tab = NULL;
	}
	del_prime(first);
	return (1);
}
