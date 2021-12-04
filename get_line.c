#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5

char * get_next_line(int fd)
{
	char buff[8000000];
	char *line;
	int i = 0;

	while (read(fd, &buff[i], BUFFER_SIZE) != 0)
	{
		buff[i + 1] = 0;
		if (buff[i] == '\n')
		{

			line = malloc(i + 2);
			strcpy(line, buff);
			// printf(" new line here .... ");
			return line;

		}
		i++;
	}
	if (i != 0)
	{
		//printf(" 00 .... ");
		buff[i + 1] = 0;
		line = malloc(i + 2);
		strcpy(line, buff);
		return line;
	}
	else
	  	return NULL;
}

int main(void)
{
	int fd = open("ss.txt", O_RDONLY);
	char *line;

   	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		// free(line);
	}
}
