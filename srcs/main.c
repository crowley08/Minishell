/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:24:41 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 13:27:59 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void run_msh(t_msh *msh)
{
	char *input;

	while (42)
	{
		input = get_input(msh);
		if (has_syntax_error(msh, input))
			continue;
		if (has_heredoc_parse_input_error(msh, input))
			continue;
		printf("input parsed final: $%s$\n", msh->input);
		if (has_parse_token_prompt_error(msh))
			continue;
		print_prompts(msh->prompt_list);

		free_msh_reset(msh);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_msh msh;

	init_msh(&msh, argc, argv, envp);
	run_msh(&msh);
	printf("minishell down...\n");
	free_msh(&msh);
	return (0);
}
