/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:46:24 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/17 08:46:26 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/apix.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	yellow(void)
{
	printf("\033[0;33m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	purple(void)
{
	printf("\033[0;35m");
}

void	reset(void)
{
	printf("\033[0m");
}
