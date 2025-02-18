/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:57:47 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/06 09:07:48 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

/*int	main(void)
{
	int	t[5];
	int	s;

	s = 5;
	t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 4;
	t[4] = 5;
	printf("%d %d %d %d %d\n", t[0], t[1], t[2], t[3], t[4]);
	ft_rev_int_tab(t, s);
	printf(" %d %d %d %d %d \n", t[0], t[1], t[2], t[3], t[4]);
	return (0);
}*/
