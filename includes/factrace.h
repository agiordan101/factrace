/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   factrace.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 14:24:16 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 15:05:35 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FACTRACE_H
# define FACTRACE_H

# define SET_SIZE 100

# include "gmp.h"
# include "stdio.h"/////////////////////////////////////////////////////////////
# include "unistd.h"
# include "stdlib.h"

typedef struct		s_prime
{
	mpz_t			prime;
	struct s_prime	*next;
}					t_prime;

void				algo_begin(char **tab, int *lastindex);
int					algo(char **tab, t_prime *lst);
int					clear_memory(int **tab, t_prime **first);

/*----------------------------- INIT PRIME NUMBERS ---------------------------*/

void				init_prime_1(int *tab);
void				init_prime_2(int *tab);
void				init_prime_3(int *tab);
void				init_prime_4(int *tab);
void				init_prime_5(int *tab);

/*---------------------------------- FT_UTILS --------------------------------*/

int					ft_tablen(char **tab);
char				**ft_tabcpy(char **src, char **dst);
char				*ft_strcpy(char *src, char *dst);
int					ft_strlen(char *nbr);
//int				is_digit(char *str);
int					ft_atoi(const char *str);

/*------------------------------------- LST -----------------------------------*/

int					ft_add_mpz_t(t_prime **last, mpz_t prime);

#endif
