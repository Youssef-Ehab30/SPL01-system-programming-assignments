#include <unistd.h>	// to use getcwd
#include <stdlib.h>	// to use exit
#include <string.h>	// to use strlen
#include <stdio.h>	// to use perror

#define ARGUMENT_ERROR -1
#define WRITE_ERROR    -2
#define GETCWD_ERROR   -3

int main (int argc, char * argv[]) {
	if (argc > 1) {
		char* error_msg = "Error in calling pwd, can't add arguments more than command name, Usage: ./pwd \n";
		if ( write(2, error_msg, strlen(error_msg)) < 0) {
			perror("Error in writing to standard error file");
			exit(WRITE_ERROR);
		}	
		exit(ARGUMENT_ERROR);
	}

	char* cwd = getcwd(NULL, 0);	// using NULL with cwd for automatic allocation (must free cwd)
	if (cwd == NULL) {
		char* error_msg = "Error in calling getcwd function \n";
                if ( write(2, error_msg, strlen(error_msg)) < 0) {
                        perror("Error in writing to standard error file");
                        exit(-2);
                }
		// or simply call perror and it will also print errno (last system call error)
		// perror(error_msg);
                exit(GETCWD_ERROR);
	}

	if ((write(1, cwd, strlen(cwd)) < 0) || (write(1, "\n", 1) < 0)) {
		perror("Error in writing to standard output file");
		exit(WRITE_ERROR);
	}

	free(cwd);
	return 0;
}
