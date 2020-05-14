/**
 * SO, 2017
 * Lab #2, Operatii I/O simple
 *
 * Task #3, Linux
 *
 * cat/cp applications
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "utils.h"
#include "xfile.h"

#define BUFSIZE	32

int main(int argc, char **argv)
{
	int fd_src, fd_dst, bytesWritten, bytesRead;
	int max_size;
	char buffer[BUFSIZE];

	if (argc < 2 || argc > 3) {
		printf("Usage:\n\t%s source_file [destination_file]\n",
			argv[0]);
		return 0;
	}

	/* Open source file for reading */
	fd_src = open(argv[1], O_RDONLY);
	DIE(fd_src < 0, "Source file did not open.");


	if (argc == 3) {
		/* Redirect stdout to destination file */
		fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
        DIE(fd_dst < 0, "Destination file did not open.");
	}
	else {
        fd_dst = STDOUT_FILENO;
	}

	memset(buffer, 0, BUFSIZE);
	while ((bytesRead = read(fd_src, buffer, BUFSIZE))) {
		DIE (bytesRead < 0, "Did not read properly.");
		bytesWritten = write(fd_dst, buffer, bytesRead);
		DIE (bytesWritten < 0, "Did not write properly.");
		memset(buffer, 0, BUFSIZE);
	

	/* Close file */
	if (argc == 3)
		DIE(close(fd_dst) < 0, "Did not close dest file properly.");
	DIE(close(fd_src) < 0, "Did not close src file properly.");
	return 0;
}