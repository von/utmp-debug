#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utmp.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>


#define UTMP_FILE		_PATH_UTMP


main(int argc, char **argv)
{
	int verbose = 0;
	int just_show = 0;

	int arg;

	extern char *optarg;
	extern int optind;

	char *utmp_file = UTMP_FILE;

	int utmp_fd;

	struct utmp utent;


	while ((arg = getopt(argc, argv, "nv"))) {
		switch(arg) {
		case 'n':
			just_show = 1;
			verbose = 1;
			break;

		case 'v':
			verbose = 1;
			break;
		}
	}

	utmp_fd = open(utmp_file, O_RDWR);

	if (utmp_fd < 0) {
		fprintf(stderr, "Could not open %s: %s", utmp_file, strerror(errno));
		exit(1);
	}

	while(read(utmp_fd, &utent, sizeof(utent) != -1) {
		
	
	
