/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:27:16 by saandria          #+#    #+#             */
/*   Updated: 2024/09/17 16:42:33 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

/*A TESTER*/

void	add_env(t_env **env, t_env *new_env)
{
	t_env    *current;

    if (!*env)
        *env = new_env;
    else
    {
        current = *env;
        while (current->next)
            current = current->next;
        current->next = new_env;
		new_env->next = NULL;
    }
}

t_env	*new_env_list(char *value)
{
	t_env    *new;

    new = (t_env *)malloc(sizeof(t_env));
    if (!new)
        return (NULL);
	new->value = ft_strdup(value);
    new->next = NULL;
    return (new);
}

void	print_env_list(t_env *env)
{
	t_env    *current;

    current = env;
    while (current)
    {
        printf("%s\n", current->value);
        current = current->next;
    }
    free(current);
}

t_env *get_env(char **env)
{
	int	i;
	t_env    *env_list;
	t_env    *tmp;

	i = 0;
	while (env[i])
		i++;
	env_list = (t_env *)malloc(sizeof(t_env) * (i + 1));
	i = 0;
	env_list = new_env_list(env[i]);
	i++;
	while (env[i])
	{
		tmp = new_env_list(env[i]);
		add_env(&env_list, tmp);
		i++;
	}
	return (env_list);
}

int main(int argc, char **argv, char **env)
{
	t_env *envp;

	(void)argc;
	(void)argv;
	envp = get_env(env);
	print_env_list(envp);
}