/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:16:02 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 11:54:59 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expand_var_heredoc(char *line, t_msh *msh)
{
	t_env	*env;
	char	*name;
	int		i;

	if (*line == '?')
		return (ft_itoa(msh->exit_status));
	else if (*line == '$')
		return (ft_strdup("288"));
	else if (ft_isspace(*line))
		return (ft_strdup("$"));
	i = 0;
	while (line && line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	if (i == 0)
		return (ft_strdup(""));
	name = ft_substr(line, 0, i);
	env = get_env_name(name, msh->envp);
	free(name);
	if (env)
		return (ft_strdup(env->value));
	return (ft_strdup(""));
}

t_bool	has_to_expand_heredoc(char *eof_input)
{
	int	i;

	i = 0;
	while (eof_input[i])
	{
		if (is_quote(eof_input[i++]))
		{
			free(eof_input);
			return (F);
		}
	}
	free(eof_input);
	return (T);
}

char	*expand_input_var(t_msh *msh, char *input, t_bool do_free)
{
	int		i;
	char	*new_input;
	t_quote	quote;

	i = 0;
	new_input = NULL;
	init_quote(&quote);
	while (input && input[i])
	{
		update_quote(input[i], &quote);
		if (input[i] == '$' && (quote_closed(quote) || quote.d_q == OPENED))
			new_input = re_new_input_var(new_input, input, &i, msh);
		else if (input[i])
			new_input = re_new_input_var(new_input, input, &i, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
}
