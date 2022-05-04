#include "main.h"

/**
 * create_file - crreate a file
 * @filename: file to be created
 * @text_content: string to be added to file
 * Return: 1 if successful -1 if not
 */

int create_file(const char *filename, char *text_content)
{
	int fd, i = 0;
	fd = open(filename, O_CREATE | RDWR | O_TRUNC, 0600);
	if(!fd)
		return -1;
	if(filename = NULL)
		return -1;
	if(text_content)
	{
		while(text_content[i] != '\0')
			I++;
		write(fd, text_content, i);
	}
	close(fd);
	return (1);
}
