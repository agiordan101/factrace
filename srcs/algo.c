/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 15:11:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:48:28 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "factrace.h"

/*
**	Algo_begin :
**	On test les premier nbr en commencant par la fin
**	Tant qu'on revient pas au debut
**	On save le premier trouve pour
**	que l'algo commence par celui d'apres dans l'ordre
*/

static int	*init_prime_numbers()
{
	int	*tab;

	if (!(tab = (int *)malloc(sizeof(int) * 125)))
		return (NULL);
	init_prime_1(tab);
	init_prime_2(tab);
	init_prime_3(tab);
	init_prime_4(tab);
	init_prime_5(tab);
	return (tab);
}

static void	test_factors(char *nbr, int *tab, t_prime *lst)
{
	mpz_t	n;
	mpz_t	reste;
	mpz_t	tmp;
	mpz_t	prime;
	int		i;

	mpz_init_set_str(n, nbr, 10);
	mpz_init_set_d(reste, 1);
	mpz_init_set_d(tmp, 691);
	mpz_init(prime);
	i = 0;
	while (mpz_cmp_ui(reste, 0) != 0)
	{
		if (i == 125)
		{
			if (lst->next)
			{
				mpz_set(prime, lst->next->prime);
				lst = lst->next;
			}
			else
			{
				mpz_nextprime(prime, lst->prime);
				ft_add_mpz_t(&lst, prime);
			}
		}
		else
			mpz_set_d(prime, tab[i++]);
		mpz_mod(reste, n, prime);
	}
	mpz_divexact(reste, n, prime);
	gmp_printf("%Zd=%Zd*%Zd\n", n, prime, reste);
}

static int	test_begin(char *nbr)
{
	mpz_t	n;
	mpz_t	reste;
	mpz_t	factor;
	mpz_t	prime;
	char	win;

	win = 0;
	mpz_init_set_str(n, nbr, 10);
	mpz_init_set_d(prime, 2);
	mpz_init(reste);
	mpz_init(factor);
	while (mpz_cmp_ui(prime, 29))
	{
		mpz_mod(reste, n, prime);
		if (!mpz_cmp_ui(reste, 0))
		{
			mpz_divexact_ui(factor, n, 2);
			gmp_printf("%Zd=%Zd*%Zd\n", n, prime, factor);
			win = 1;
			break ;
		}
		mpz_nextprime(prime, prime);
	}
	mpz_clear(n);
	mpz_clear(reste);
	mpz_clear(factor);
	mpz_clear(prime);
	return (win);
}

void		algo_begin(char **tab, int *lastindex)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	while (tab[--i] != *tab)
		if (test_begin(tab[i]))
		{
			*lastindex = i;
			return ;
		}
}

int			algo(char **tab, t_prime *first)
{
	int		*tabprime;

	if (!(tabprime = init_prime_numbers()))
		return (-1);
	while (*tab)
	{
		test_factors(*tab, tabprime, first);
		tab++;
	}
	clear_memory(&tabprime, &first);
	return (1);
}
