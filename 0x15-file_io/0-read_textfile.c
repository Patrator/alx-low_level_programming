#include "main.h"
/**
 * read_textfile - reads text file and prints it to stdout
 * @filename: Name of file to be read
 * @letters: exact number of letter to be printed
 * Return: 0 if it fails, else the number of characters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Declare variables to be used */
	int fd;
	char *alc;
	ssize_t numread, numwrt;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return 0;
	if(filename == NULL)
		return 0;
	/* malloc space */
	alc = malloc(sizeof(char)*letters);
	if(alc==NULL)
		return(0);
	/* Reading the text file */
	numread = read(fd, alc,letters);
	/* Write to stdout */
	numwrt = write(STDOUT_FILENO, alc, numread);
	free(alc);
	close(fd);
	return (numwrt);
}
