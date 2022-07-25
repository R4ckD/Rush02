/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:30:11 by caliaga-          #+#    #+#             */
/*   Updated: 2022/07/24 19:22:57 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_error(void);

int ft_sign_analize(int *c, char *str);

int atoi_e_signed (char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
		c++;
	/* Con esta función analizamos el signo y devuelve error si es negativo */
	s = ft_sign_analize(&c, str);
	while ((str[c] != '\0') && (str[c] >= '0' && str[c] <= '9'))
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}
/* INPUT STREAM */
char	in_stream(int argc, char **argv)
{
	int		i;
	char	*estandar;
	char	param[2];

	estandar = "numbers.dict";
	if (argc == 2)
	{
		param[0] = *estandar;
		param[1] = argv[1];
	}
	else if (argc == 3)
	{
		param[0] = argv[1];
		param[1] = argv[2];
	}

	if (atoi_e_signed(param[1]) >=  0)
		return (param);
}
/*** MAIN ****/
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	int fd;
	ssize_t  n_bytes;
	char buf[2000];

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1) 
	{
		printf("Error  de apertura de archivo");
	}
	else
	{
		n_bytes = read(fd, buf, 2000);
		if	(n_bytes == 0)
		{
			printf ("No se abre");
		}
		else 
		{
			printf("%d y su contenido %s \n", (int)n_bytes, buf);
		}
	}




	int	i = -1; /* Contador */
	int row = 3;
	char	**tab = (char **)malloc(sizeof(char **) * row);
	while (++i < row)
		tab[i] = argv[i];

	//printf ("1 argumento: %s \n", tab[0]);
	//printf ("2 argumento: %s \n", tab[1]);
	//printf ("3 argumento: %s \n", tab[2]);
	//printf ("4 argumento: %s \n", tab[3]);
}
