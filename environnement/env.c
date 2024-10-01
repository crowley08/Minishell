/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:43:59 by saandria          #+#    #+#             */
/*   Updated: 2024/10/01 23:35:29 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**env_copy(t_env **env)
{
	t_env	*tmp;
	char	**env_copy;
	char	*tmp_copy;
	int		i;

	tmp = *env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env_copy = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = *env;
	while (tmp)
	{
		tmp_copy = ft_strjoin(tmp->name, "=");
		env_copy[i] = ft_strjoin(tmp_copy, tmp->value);
		free(tmp_copy);
		i++;
		tmp = tmp->next;
	}
	env_copy[i] = NULL;
	return (env_copy);
}
