/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_analize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:02:04 by caliaga-          #+#    #+#             */
/*   Updated: 2022/07/24 17:35:30 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_error(void);

int	ft_sign_analize(int *c, char *str)
{
	int	s;

	s = 1;
	while ((str[*c] != '\0') && (str[*c] == '+' || str[*c] == '-'))
	{
		if (str[*c] == '-')
		{
			ft_error();
			return (1);
		}
		else if (str[*c] == '+')
			s *= 1;
		*c = *c + 1;
	}
	return (s);
}
