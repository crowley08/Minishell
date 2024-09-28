/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:11:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/28 13:16:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

t_bool is_trimmed(char *str);
char **split_pipe(char *str);
void print_prompts(char **prompts);
#endif
