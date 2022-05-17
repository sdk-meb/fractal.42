/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:45:35 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/16 17:45:37 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double  map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
