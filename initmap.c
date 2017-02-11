/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:06:41 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/10 16:32:37 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mallocmap(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->map = (int**)malloc(sizeof(int*) * env->yend)))
		return (0);
	while (i < env->yend)
	{
		if (!(env->map[i] = (int*)malloc(sizeof(int) * env->xend)))
			return (0);
		i++;
	}
	return (0);
}

int		calculationmap(t_env *env, char *str)
{
	int		xbegin;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		xbegin = 0;
		while (str[i] != '\0')
		{
			if (ft_iswhitespace(str[i + 1]) && ft_isalnum(str[i]))
				xbegin++;
			i++;
		}
		xbegin++;
		if (xbegin > env->xend)
			env->xend = xbegin;
	}
	return (0);
}

int		createmap2(t_env *env, char **tab, int ybegin)
{
	int xbegin;
	int i;
	int o;

	i = 0;
	xbegin = 0;
	o = xbegin;
	while (o <= env->xend)
	{
		env->map[ybegin][o] = 0;
		o++;
	}
	while (tab[i] != NULL && xbegin < env->xend)
	{
		env->map[ybegin][xbegin] = ft_atoi(tab[i]);
		xbegin++;
		i++;
	}
	return (0);
}

int		createmap(t_env *env, char **argv)
{
	int		fd;
	char	*str;
	char	**tab;
	int		ybegin;

	ybegin = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str) == 1 && ybegin < env->yend)
	{
		tab = ft_strsplit(str, ' ');
		createmap2(env, tab, ybegin);
		ybegin++;
		ft_memdel((void**)&str);
	}
	ft_memdel((void**)tab);
	return (0);
}

int		read_argv(t_env *env, char **argv)
{
	int		fd;
	char	*str;

	env->yend = 0;
	env->xend = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File not valid, can't create the map.\n");
		return (1);
	}
	while (get_next_line(fd, &str) == 1)
	{
		calculationmap(env, str);
		env->yend++;
		ft_memdel((void**)&str);
	}
	mallocmap(env);
	close(fd);
	createmap(env, argv);
	return (0);
}
