/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:13:34 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 19:28:50 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** IMG(10,10) = 10 * 10 = 100 = 100 * 32 = 3200 / 8 = 400;
** 10 * 10 * 32 / 8;
** PXL = 4 octets (R,V,B,A); 4 * 8 = 32;
** OCTETS = 8 bits (11 11 11 11);
** env.bits = 32 -> 32 / 8 = 4;
** env.color.oct[0] = 0xFF8C00;
** env.color.oct[1] = 0xABC8E2;
** env.color.oct[2] = 0xA8ACA8;
** env.color.oct[3] = 0xFFFFE0;
** env.color.oct[4] = 0x609CA0;
** env.color.oct[5] = 0x20B4A8;
** env.color.oct[6] = 0xFF0000;
** env.color.oct[7] = 0x7868E8;
*/

int		exposehook(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	ft_bzero(env->data, WIDTH * HEIGHT * env->bits / 8);
	linkdots(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		initwindow(t_env env, char **argv)
{
	if (read_argv(&env, argv) == 1)
		return (0);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "fdf");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.data = mlx_get_data_addr(env.img, &(env.bits), &(env.size),
	&(env.endian));
	env.height = HEIGHT / 3;
	env.width = WIDTH / 2;
	env.zoom = 20;
	env.depth = 0;
	mlx_expose_hook(env.win, exposehook, &env);
	mlx_key_hook(env.win, keyevent, &env);
	mlx_hook(env.win, 17, 0, destroywindow, &env);
	mlx_loop(env.mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	char	*str;

	env.color = (t_color){{0xFF8C00, 0xABC8E2, 0xA8ACA8, 0xFFFFE0,
					0x609CA0, 0x20B4A8, 0xFF0000, 0x7868E8}};
	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf Name_of_the_file\n");
		return (0);
	}
	else
	{
		ft_putstr("Do you want to color your octants before ? Yes/No\n");
		if (get_next_line(0, &str) == 1)
		{
			if (ft_strncmp(str, "Yes", 3) == 0 || ft_strncmp(str, "y", 1) == 0)
			{
				ft_memdel((void**)&str);
				usecolor(&env, str);
			}
		}
	}
	initwindow(env, argv);
	return (0);
}
