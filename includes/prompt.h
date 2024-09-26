/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:11:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 14:13:23 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

t_bool is_trimmed(char *str);
char *trim_space_out(char *input);
int str_trim_in_len(char *str);
char *trim_space_in(char *input);
char *trim_space_all(char *input);
char **split_pipe(char *str);
void print_prompts(char **prompts);
#endif
