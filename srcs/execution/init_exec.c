/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:25:23 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/10 12:51:29 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_path(char *cmd, t_env *envp)
{
	t_env *env_path;
	int i;
	char **paths;
	char *path;

	env_path = get_env("PATH", envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path->value, ':');
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path = heredoc_strjoin(path, cmd);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			break;
		free(path);
		path = NULL;
	}
	ft_free_tab_str(paths);
	return (path);
}

void exec_cmd(t_cmd *cmd, t_env *envp)
{
	char *path;
	char **arg;
	char **env;

	if (!cmd)
		return;
	path = get_path(cmd->cmd, envp);
	if (path)
	{
		//? leak memory
		arg = set_arg_execve(cmd);
		env = set_env_execve(envp);
		// ft_printf("Path for %s: %s\n", cmd->cmd, path);
		if (execve(path, arg, env) == -1)
		{
			//! exit
			ft_printf("Failed to exec\n");
			ft_free_tab_str(arg);
			ft_free_tab_str(env);
			free(path);
		}
	}
	else
		ft_printf("Path not found for %s\n", cmd->cmd);
}

// void exec_prompt(t_prompt *prompt, t_env *envp, int *fd)
// {
// 	pid_t pid;
// 	int fd_in_file;
// 	int fd_out_file;

// 	pid = fork();
// 	if (pid == -1)
// 		return;
// 	if (pid == 0)
// 	{
// 		fd_in_file = set_redir_in(prompt->redir_in);
// 		fd_out_file = set_redir_out(prompt->redir_out);
// 		if (fd_in_file == -1 || fd_in_file == -1)
// 			return;
// 		if (fd_in_file == 0)
// 			dup2(fd[0], STDIN_FILENO);
// 		else
// 		{
// 			dup2(fd_in_file, STDIN_FILENO);
// 			close(fd[0]);
// 		}
// 		if (fd_out_file == 1)
// 			dup2(fd[1], STDOUT_FILENO);
// 		else
// 		{
// 			dup2(fd_out_file, STDOUT_FILENO);
// 			close(fd[1]);
// 		}
// 		exec_cmd(prompt->cmd, envp);
// 	}
// 	wait(NULL);
// 	close(fd[1]);
// }

// void exec_last_prompt(t_prompt *prompt, t_env *envp, int *fd, int std_out)
// {
// 	pid_t pid;
// 	int fd_in_file;
// 	int fd_out_file;

// 	pid = fork();
// 	if (pid == -1)
// 		return;
// 	if (pid == 0)
// 	{
// 		fd_in_file = set_redir_in(prompt->redir_in);
// 		fd_out_file = set_redir_out(prompt->redir_out);
// 		if (fd_in_file == -1 || fd_in_file == -1)
// 			return;
// 		if (fd_in_file == 0)
// 			dup2(fd[0], STDIN_FILENO);
// 		else
// 		{
// 			dup2(fd_in_file, STDIN_FILENO);
// 			close(fd[0]);
// 		}
// 		close(fd[1]);
// 		if (fd_out_file == 1)
// 			dup2(std_out, STDOUT_FILENO);
// 		else
// 			dup2(fd_out_file, STDOUT_FILENO);
// 		exec_cmd(prompt->cmd, envp);
// 	}
// 	wait(NULL);
// 	close(fd[1]);
// }

// //! FIXME: this function
// void exec_list_prompt(t_prompt *prompt, t_env *envp)
// {
// 	int std_in;
// 	int std_out;
// 	int fd[2];

// 	std_in = dup(STDIN_FILENO);
// 	std_out = dup(STDOUT_FILENO);
// 	if (pipe(fd) == -1)
// 		return;
// 	while (prompt->next)
// 	{
// 		exec_prompt(prompt, envp, fd);
// 		prompt = prompt->next;
// 	}
// 	exec_last_prompt(prompt, envp, fd, std_out);
// 	dup2(std_in, STDIN_FILENO);
// 	dup2(std_out, STDOUT_FILENO);
// 	close(std_in);
// 	close(std_out);
// }

void exec_prompt(t_prompt *prompt, t_env *envp)
{
	pid_t pid;
	int fd[2];

	if (pipe(fd) == -1)
		return;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_cmd(prompt->cmd, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
void exec_last_prompt(t_prompt *prompt, t_env *envp)
{
	pid_t pid;
	int fd[2];
	if (pipe(fd) == -1)
		return;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		exec_cmd(prompt->cmd, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		close(fd[0]);
	}
}

void exec_list_prompt(t_prompt *prompt, t_env *envp)
{
	int std_in;
	int std_out;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);

	while (prompt->next)
	{
		exec_prompt(prompt, envp);
		prompt = prompt->next;
	}
	dup2(std_out, STDOUT_FILENO);
	exec_last_prompt(prompt, envp);
	dup2(std_in, STDIN_FILENO);
}
