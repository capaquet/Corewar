/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_common.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:54:16 by lbelda            #+#    #+#             */
/*   Updated: 2018/06/27 11:57:14 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_COMMON_H
# define V_COMMON_H

# include "unistd.h"
# include "fcntl.h"
# include "libft.h"
# include "ft_printf.h"

void	m_pro(int ret);
void	m_pro_null(void *ret);
void	m_pro_null_bonus(void *ret, char *str);
void	free_pro(void **ptr);

void	error_exit(const char *str);

#endif
