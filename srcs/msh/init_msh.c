/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:38:54 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/21 15:25:17 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void init_msh_ok(int argc, char *argv[], t_msh *msh)
{
	(void)argc;
	(void)argv;
	msh->std_in = dup(STDIN_FILENO);
	msh->std_out = dup(STDOUT_FILENO);
	msh->exit_status = EXIT_SUCCESS;
	msh->input = NULL;
	msh->env_list = NULL;
	msh->heredoc_list = NULL;
	msh->prompt_list = NULL;
}

void exit_msh_eof(t_msh *msh)
{
	free_msh(msh, TRUE);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

void run_msh(t_msh *msh)
{
	while (42)
	{
		printf("==================== EXIT STATUS %d =====\n", msh->exit_status);
		if (!get_input_line_ok(msh))
			continue;
		if (!syntax_input_ok(msh))
			continue;
		if (!heredoc_parse_input_ok(msh))
			continue;
		if (!parse_token_prompt_ok(msh))
			continue;
		// printf("->%s\n", msh->input);
		// print_prompts(msh->prompt_list);
		// free_msh_reset(msh, TRUE);
		execute_msh(msh);
	}
}
