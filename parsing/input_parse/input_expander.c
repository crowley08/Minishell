/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:05 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:42:32 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*re_new_input_expander(char *old_input, char *input, int *i,
							t_env **list)
{
	char	*c;
	int		len;
	char	*value;

	if (list && *list)
	{
		*i += 1;
		value = expander_var(input + *i, *list);
		old_input = heredoc_strjoin(old_input, value);
		len = 0;
		while (input && input[*i + len] && (ft_isalnum(input[*i + len])
				|| input[*i + len] == '_'))
			len++;
		*i += len;
	}
	else if (input && *input)
	{
		c = ft_substr(input + *i, 0, 1);
		old_input = heredoc_strjoin(old_input, c);
		*i += 1;
		free(c);
	}
	return (old_input);
}

char	*get_new_input_expander(char *input, t_env *envp, t_bool do_free)
{
	t_quote_type	quote;
	int				i;
	char			*new_input;

	new_input = NULL;
	i = 0;
	init_quote_dt(&quote);
	while (input && input[i])
	{
		update_quote_dt(input[i], &quote);
		if (input[i] == '$' && (quote.d_q == OPENED
				|| (quote.d_q == CLOSED && quote.s_q == CLOSED)))
			new_input = re_new_input_expander(new_input, input, &i, &envp);
		else if (input[i])
			new_input = re_new_input_expander(new_input, input, &i, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
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
	while (str && str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i == 0)
		return (NULL);
	name = ft_substr(str, 0, i);
	env = get_env_name(name, envp);
	free(name);
	if (env)
		return (env->value);
	return (NULL);
}

t_bool	fill_file_input(int fd, t_heredoc heredoc, t_env *envp)
{
	char	*input;

	while (42)
	{
		rl_on_new_line();
		input = readline("> ");
		if (!input || is_empty_line(input))
		{
			free(input);
			write(fd, "\n", 1);
			continue ;
		}
		else
		{
			if (ft_strncmp(input, heredoc.eof, ft_strlen(input)) == 0)
			{
				free(input);
				return (TRUE);
			}
			// write(fd, input, ft_strlen(input));
			write_heredoc_input(fd, input, heredoc.expend_var, envp);
			write(fd, "\n", 1);
		}
		free(input);
	}
}
