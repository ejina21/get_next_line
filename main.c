#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);

	char *line;
	int i;
	while ((i = get_next_line(fd, &line)))
	{
		printf("%i = %s\n", i, line);
		free(line);
	}
	printf("%i = %s\n", i, line);
	free(line);
}
