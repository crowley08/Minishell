/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:17:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/18 11:00:20 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*list_env;
	t_env	*env;

	(void)argv;
	(void)argc;
	if (!(list_env = envp_dup(envp)))
	{
		ft_printf("Error: Failed to duplicate environment variables\n");
	}
	env = env_create("TEST=test", '=');
	env_add(list_env, env);
	env = env_create("TEST=test111111111111111111111111111111", '=');
	env_add(list_env, env);
	env = list_env;
	while (env)
	{
		ft_printf("%s = %s\n", env->name, env->value);
		env = env->next;
	}
	ft_printf("\n\n\n");
	env = env_get(list_env, "TEST");
	if (env)
		ft_printf("TEST = %s\n", env->value);
	else
		ft_printf("TEST = NULL\n");
	ft_printf("\n\n\n");
	env_del(list_env, "TEST");
	env_del(list_env, "PATH");
	env = list_env;
	while (env)
	{
		ft_printf("%s = %s\n", env->name, env->value);
		env = env->next;
	}
	env_free_list(list_env);
	return (0);
}
