/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser_expander.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:29:55 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/13 19:58:56 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	env = get_env(name, msh->env_list);
	free(name);
	if (env)
		return (ft_strdup(env->value));
	return (ft_strdup(""));
}

char	*re_new_input_heredoc(char *old_input, char *input, t_heredoc **list)
{
	char	*tmp_c;

	if (list && *list)
	{
		old_input = msh_strjoin(old_input, "<");
		old_input = msh_strjoin(old_input, (*list)->tmp_file);
		(*list) = (*list)->next;
	}
	else if (input && *input)
	{
		tmp_c = ft_substr(input, 0, 1);
		old_input = msh_strjoin(old_input, tmp_c);
		free(tmp_c);
	}
	return (old_input);
}

char	*parse_input_heredoc(t_heredoc *list, char *input, t_bool do_free)
{
	int			i;
	char		*new_input;
	t_quote_dt	quote;

	i = 0;
	new_input = NULL;
	init_quote(&quote);
	while (input && input[i])
	{
		update_quote(input[i], &quote);
		if (quote_closed(quote) && input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			if (ft_isspace(input[i]))
				i++;
			i += get_eof_len(input + i);
			new_input = re_new_input_heredoc(new_input, 0, &list);
		}
		else
			new_input = re_new_input_heredoc(new_input, input + i++, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
}

char	*re_new_input_var(char *old_input, char *input, int *i, t_msh *msh)
{
	int		len;
	char	*tmp_c;
	char	*value;

	if (msh && msh->env_list)
	{
		*i += 1;
		value = expand_var_heredoc(input + *i, msh);
		old_input = msh_strjoin(old_input, value);
		free(value);
		len = 0;
		while (input && input[*i + len] && (ft_isalnum(input[*i + len])
				|| input[*i + len] == '_'))
			len++;
		*i += len;
	}
	else if (input && *input)
	{
		tmp_c = ft_substr(input + *i, 0, 1);
		old_input = msh_strjoin(old_input, tmp_c);
		free(tmp_c);
		*i += 1;
	}
	return (old_input);
}

char	*expand_input_var(t_msh *msh, char *input, t_bool do_free)
{
	int			i;
	char		*new_input;
	t_quote_dt	quote;

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