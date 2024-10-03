/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:23:48 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/03 11:53:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*re_new_input_var_quote(char *old_input, char *input, int *i,
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
		while (input && input[*i + len] && (ft_isalpha(input[*i + len])
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

char	*get_new_input_var_quote(char *input, t_env *envp)
{
	t_quote_dt	quote;
	int			i;
	char		*new_input;

	new_input = NULL;
	i = 0;
	init_quote_dt(&quote);
	while (input && input[i])
	{
		update_quote_dt(input[i], &quote);
		if (input[i] == '$' && (quote.d_q == OPENED || (quote.d_q == CLOSED
					&& quote.s_q == CLOSED)))
			new_input = re_new_input_var_quote(new_input, input, &i, &envp);
		else
			new_input = re_new_input_var_quote(new_input, input, &i, NULL);
	}
	free(input);
	return (new_input);
}
