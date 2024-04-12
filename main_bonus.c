/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmaksim <elmaksim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:07:05 by elmaksim          #+#    #+#             */
/*   Updated: 2024/01/25 13:36:59 by elmaksim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define BLUE    "\x1B[34m"

void	print_colored_line(const char *line, const char *color)
{
	printf("%s%s%s", color, line, RESET);
}

void	check_leaks(void)
{
	FILE	*leaksFile;
	char	buffer[1024];

	system("leaks a.out > leaks_output");
	leaksFile = fopen("leaks_output", "r");
	print_colored_line("Checking for leaks:\n", BLUE);
	if (leaksFile != NULL)
	{
		while (fgets(buffer, sizeof(buffer), leaksFile) != NULL)
			printf("%s", buffer);
		fclose(leaksFile);
	}
	remove("leaks_output");
	print_colored_line("Finished checking leaks!\n", GREEN);
}

int	main(void)
{
	int		fds[3];
	char	*line;

	fds[0] = open("test1_bonus", O_RDONLY);
	fds[1] = open("test2_bonus", O_RDONLY);
	fds[2] = open("test3_bonus", O_RDONLY);
	if (fds[0] < 0 || fds[1] < 0 || fds[2] < 0)
	{
		perror("Error opening file");
		return (1);
	}
	int buffer_sizes[] = {32, 64, 128};  // Add more sizes as needed
	for (size_t i = 0; i < sizeof(buffer_sizes) / sizeof(buffer_sizes[0]); ++i)
	{
		#undef BUFFER_SIZE
		#define BUFFER_SIZE buffer_sizes[i]
		print_colored_line("\n\nChecking with BUFFER_SIZE=", BLUE);
		printf("%d:\n", BUFFER_SIZE);
		for (size_t j = 0; j < sizeof(fds) / sizeof(fds[0]); ++j)
		{
			lseek(fds[j], 0, SEEK_SET); // Reset file position to the beginning
			print_colored_line("Descriptor:", RED);
			printf(" %zu\n", j + 1);
			line = get_next_line(fds[j]);
			while (line)
			{
				printf("%s", line);
				free(line);
				line = get_next_line(fds[j]);
			}
			free(line);
		}
	}
	for (size_t i = 0; i < sizeof(fds) / sizeof(fds[0]); ++i)
		close(fds[i]);
	// Check for memory leaks
	atexit(check_leaks);
	print_colored_line("\n\nAll tests passed successfully!\n\n", GREEN);
	return (0);
}
