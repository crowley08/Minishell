/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:30 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/08 15:11:04 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_len_arg(t_arg *list)
{
	int len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

int get_len_envp(t_env *envp)
{
	int len;
	len = 0;
	while (envp)
	{
		len++;
		envp = envp->next;
	}
	return (len);
}

char **set_arg_execve(t_prompt *prompt)
{
	char **arg;
	int len;
	int i;

	len = 2;
	i = 1;
	len += get_len_arg(prompt->cmd->args);
	arg = malloc(sizeof(char *) * len);
	arg[0] = ft_strdup(prompt->cmd->cmd);
	while (i < len - 1)
	{
		arg[i++] = ft_strdup(prompt->cmd->args->value);
		prompt->cmd->args = prompt->cmd->args->next;
	}
	arg[len - 1] = NULL;
	return (arg);
}

char **set_env_execve(t_env *envp)
{
	char **list;
	char *env;
	int len;
	int i;

	len = 1;
	i = 0;
	len += get_len_envp(envp);
	list = malloc(sizeof(char *) * len);
	while (i < len - 1)
	{
		env = ft_strjoin(envp->name, "=");
		env = heredoc_strjoin(env, envp->value);
		list[i++] = env;
		envp = envp->next;
	}
	list[len - 1] = NULL;
	return (list);
}

