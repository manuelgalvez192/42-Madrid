/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:13:05 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/14 20:30:02 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* --- main --- */
void	child_process(int fd[2], char **argv, char **envp);
void	parent_process(int fd[2], char **argv, char **envp);
void	command_exec(char **envp, char **argv, int index);

/* --- check --- */
void	error(char *msg);
int		ft_strlen(const char *str);
int		check_fd(char *file);
int		check_cmd(char **envp, char **argv, int index);
void	*ft_calloc(size_t count, size_t size);

/* --- path ---- */
int		path_finder(char **envp);
char	*locate_path(char **split_path, char *cmd);
char	*make_path(char *split_path, char *cmd);

/* --- split ---- */
size_t	count_words(char const *s, char c);
char	**free_arr(char **arr, size_t i);
char	*allocate_word(char const *start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);

#endif