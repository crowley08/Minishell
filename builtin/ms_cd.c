/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:05:14 by saandria          #+#    #+#             */
/*   Updated: 2024/10/08 16:42:49 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_args(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 2)
		return (1);
	return (0);
}

void	ms_cd(char **cmd, char **env)
{
	char	*path;

	(void)env;
	if (check_args(cmd))
	{
		if (cmd[1][0] == '~')
			path = ft_strjoin(getenv("HOME"), &cmd[1][1]);
		else
			path = ft_strdup(cmd[1]);
		if (chdir(path) == -1)
		{
			ft_putstr_fd("cd", 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		free(path);
	}
	return ;
}
