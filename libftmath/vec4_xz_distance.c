/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_xz_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:08:06 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 19:08:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	vec4_xz_distance(t_vec4 a, t_vec4 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.z - a.z, 2)));
}
