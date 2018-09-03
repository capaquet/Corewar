/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:28:04 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/07 16:28:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	dot_product(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}