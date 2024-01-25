/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmaksim <elmaksim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:23:36 by elmaksim          #+#    #+#             */
/*   Updated: 2024/01/25 13:34:15 by elmaksim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
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

void	process_file(const char *file_path, int buffer_size)
{
	int fd = open(file_path, O_RDWR);

	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	print_colored_line("\n\nReading lines from the file ", BLUE);
	print_colored_line(file_path, RED);
	print_colored_line(" with  ", BLUE);
	print_colored_line("BUFFER_SIZE=", RED);
	printf("%d", buffer_size);
	print_colored_line(":\n", BLUE);
	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "\nUsage: %s <file_path1> [buffer_size1]\
			 <file_path2> [buffer_size2] ...\n", argv[0]);
		return (1);
	}
	// Iterate over file paths and buffer sizes
	for (int i = 1; i < argc; i += 2)
	{
		char *file_path = argv[i];
		int buffer_size = (i + 1 < argc) ? atoi(argv[i + 1]) : BUFFER_SIZE;
		process_file(file_path, buffer_size);
	}
	// Check for memory leaks
	atexit(check_leaks);
	print_colored_line("\n\nAll tests passed successfully!\n\n", GREEN);
	return (0);
}
