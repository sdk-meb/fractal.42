/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:30:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/12 09:30:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/apix.h"

char *check_name(int c, char **name)
{
 	char *acronyms;

	if (c == 1)
		exit(ft_printf("we can't find any fractol set name"));
	acronyms = malloc(c);
	acronyms[c - 1] = '\0';
 	while (--c)
	{
		if (!ft_memcmp(name[c], "mandelbrot", 11))
			acronyms[c - 1] = 'm';
		else
			exit(ft_printf("we can't find this fractol set : %s", name[c]));
	}
	return (acronyms);
}