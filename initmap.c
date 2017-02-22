/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:06:41 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/22 12:49:34 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		mallocmap(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->map = (int**)malloc(sizeof(int*) * env->yend)))
		exit(-1);
	while (i < env->yend)
	{
		if (!(env->map[i] = (int*)malloc(sizeof(int) * env->xend)))
			exit(-1);
		i++;
	}
}

static void		calculationmap(t_env *env, char *str)
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
		if (ft_isalnum(str[i - 1]))
			xbegin++;
		if (xbegin > env->xend)
			env->xend = xbegin;
	}
}

static void		createmap2(t_env *env, char **tab, int ybegin)
{
	int xbegin;
	int i;

	i = 0;
	xbegin = 0;
	while (xbegin < env->xend)
	{
		env->map[ybegin][xbegin] = 0;
		xbegin++;
	}
	xbegin = 0;
	while (xbegin < env->xend && tab[i] != NULL)
	{
		env->map[ybegin][xbegin] = ft_atoi(tab[i]);
		xbegin++;
		i++;
	}
}

static void		createmap(t_env *env, int fd, char **argv)
{
	char	*str;
	char	**tab;
	int		ybegin;

	ybegin = 0;
	fd = open(argv[1], O_RDONLY);
	while (ybegin < env->yend && get_next_line(fd, &str) == 1)
	{
		tab = ft_strsplit(str, ' ');
		if (tab == NULL)
			exit(-1);
		createmap2(env, tab, ybegin);
		ft_memdel((void**)&str);
		ft_tabdel((void***)&tab);
		ybegin++;
	}
}

int				read_argv(t_env *env, int fd, char **argv)
{
	char	*str;

	env->yend = 0;
	env->xend = 0;
	while (get_next_line(fd, &str) == 1)
	{
		calculationmap(env, str);
		ft_memdel((void**)&str);
		env->yend++;
	}
	close(fd);
	if (env->xend >= 2 && env->yend >= 2)
	{
		mallocmap(env);
		createmap(env, fd, argv);
	}
	else
		return (1);
	return (0);
}
