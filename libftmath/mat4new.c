/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:43:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 21:14:41 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	mat4new(t_vec4 x, t_vec4 y, t_vec4 z, t_vec4 w)
{
	t_mat4	mat;

	mat.x = x;
	mat.y = y;
	mat.z = z;
	mat.w = w;
	return (mat);
}
