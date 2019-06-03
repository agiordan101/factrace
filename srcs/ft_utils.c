/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 15:55:23 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 16:35:08 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "factrace.h"

char	**ft_tabcpy(char **src, char **dst)
{
	int	index;

	if (!src)
		return (NULL);
	index = -1;
	while (src[++index])
		dst[index] = src[index];
	return (dst);
}

char	*ft_strcpy(char *src, char *dst)
{
	int	index;

	if (!src)
		return (NULL);
	index = -1;
	while (src[++index])
		dst[index] = src[index];
	return (dst);
}

int		ft_tablen(char **tab)
{
	int index;

	if (!tab)
		return (0);
	index = -1;
	while (tab[++index])
		;
	return (index);
}

int		ft_strlen(char *str)
{
	int count;

	if (!str)
		return (0);
	count = -1;
	while (str[++count])
		;
	return (count);
}
