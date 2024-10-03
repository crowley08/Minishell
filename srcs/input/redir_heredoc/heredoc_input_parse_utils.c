/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_input_parse_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:51:02 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/01 22:59:47 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	write_heredoc_input(int fd, char *input, t_bool exp_var, t_env *envp)
{
	char	*value;
	int		i;

	if (exp_var)
	{
		while (input && *input)
		{
			if (*input == '$')
			{
				i = 0;
				value = expander_var(++input, envp);
				write(fd, value, ft_strlen(value));
				while (input && input[i] && (ft_isalpha(input[i])
						|| input[i] == '_'))
					i++;
				input += i;
			}
			else
				write(fd, input++, 1);
		}
	}
	else
		write(fd, input, ft_strlen(input));
}

char	*expander_var(char *str, t_env *envp)
{
	t_env	*env;
	int		i;
	char	*name;

	i = 0;
	if (str[i] == '?')
		return (NULL); // !FIXME:status code of the most recently execution
	if (ft_isspace(str[i]))
		return ("$");
	if (str[i] == '$')
		return ("288");
	while (str && str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		i++;
	if (i == 0)
		return (NULL);
	name = ft_substr(str, 0, i);
	env = get_env(name, envp);
	free(name);
	if (env)
		return (env->value);
	return (NULL);
}
