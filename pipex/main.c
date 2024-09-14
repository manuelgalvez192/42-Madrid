/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:39:07 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/14 20:47:17 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if(envp == NULL || envp[0] == NULL || path_finder(envp) == 0)
		error("Error: PATH not found\n");
	if (argc != 5)
		error("Error: Wrong number of arguments\n");
	if(check_fd(argv[1]))
		error("Error: File not found\n");
	if(check_cmd(envp, argv, 2))
		error("Error: Command not found\n");
	pipe(fd);
	pid = fork();
	if (pid == -1)
		error("Error: fork failed");
	if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(fd, argv, envp);
	return (0);
}

void	child_process(int fd[2], char **argv, char **envp)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	command_exec(envp, argv, 2);
}

void	parent_process(int fd[2], char **argv, char **envp)
{
	int	outfile;

	wait(0);
	outfile = open(argv[4], O_WRONLY);
	if (outfile == -1)
		outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	command_exec(envp, argv, 3);
}

void	command_exec(char **envp, char **argv, int index)
{
	char	**split_path;
	char	**arguments;
	char	*path;
	int		i;

	i = path_finder(envp);
	split_path = ft_split(envp[i], ':');
	path = locate_path(split_path, argv[index]);
	arguments = ft_split(argv[index], ' ');
	execve(path, arguments, NULL);
}
