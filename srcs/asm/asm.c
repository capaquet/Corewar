/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:34:20 by achirat           #+#    #+#             */
/*   Updated: 2018/06/28 09:37:54 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static int	ft_control_arg(int argc, char **argv, int *fd_r)
{
	int	len;

	if ((*fd_r = open(argv[argc - 1], O_RDONLY)) == -1)
		ft_print_error(argv[argc - 1]);
	len = ft_strlen((argv[argc - 1]));
	if (len < 2)
		ft_print_error(argv[argc - 1]);
	if (argv[argc - 1][len - 1] == 's' && argv[argc - 1][len - 2] == '.')
		return (1);
	ft_print_error(argv[argc - 1]);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd_r;
	int		fd_w;
	char	*new;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc < 2)
		ft_print_usage(argv);
	if (ft_control_arg(argc, argv, &fd_r))
	{
		new = ft_get_name(argv[argc - 1], 0, 0, 0);
		ft_get_instructions(fd_r, &(data.parse), &data);
		ft_check_parse(&data);
		if (!(fd_w = open(new, O_CREAT | O_WRONLY | O_TRUNC, 0644)))
			exit(1);
		ft_write_header(fd_w, data);
		ft_printf("Writing output program to %s\n", new);
		ft_free_data(data);
		close(fd_r);
		close(fd_w);
		free(new);
	}
	return (0);
}
