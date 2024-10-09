/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expander_dequote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:23:48 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/09 14:19:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *re_new_input_expander(char *old_input, char *input, int *i,
							t_env **list)
{
	char *c;
	int len;
	char *value;

	if (list && *list)
	{
		*i += 1;
		value = expander_var(input + *i, *list);
		old_input = heredoc_strjoin(old_input, value);
		len = 0;
		while (input && input[*i + len] && (ft_isalnum(input[*i + len]) || input[*i + len] == '_'))
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

char *get_new_input_expander(char *input, t_env *envp, t_bool do_free)
{
	t_quote_dt quote;
	int i;
	char *new_input;

	new_input = NULL;
	i = 0;
	init_quote_dt(&quote);
	while (input && input[i])
	{
		update_quote_dt(input[i], &quote);
		if (input[i] == '$' && (quote.d_q == OPENED || (quote.d_q == CLOSED && quote.s_q == CLOSED)))
			new_input = re_new_input_expander(new_input, input, &i, &envp);
		else if (input[i])
			new_input = re_new_input_expander(new_input, input, &i, NULL);
	}
	if (do_free)
		free(input);
	return (new_input);
}

char *get_new_input_unquote(char *input, t_bool do_free)
{
	t_quote_dt quote;
	int i;
	char *new_input;
	char *c;

	new_input = NULL;
	i = 0;
	init_quote_dt(&quote);
	while (input && input[i])
	{
		if (is_quote(input[i]) && (quote.d_q == CLOSED && quote.s_q == CLOSED))
			update_quote_dt(input[i++], &quote);
		update_quote_dt(input[i], &quote);
		if (is_quote(input[i]) && (quote.d_q == CLOSED && quote.s_q == CLOSED))
			update_quote_dt(input[++i], &quote);
		if (input[i])
		{
			c = ft_substr(input + i++, 0, 1);
			new_input = heredoc_strjoin(new_input, c);
			free(c);
		}
	}
	if (do_free)
		free(input);
	return (new_input);
}
