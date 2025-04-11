#include <unistd.h>     // to use write
#include <string.h>     // to use strlen
#include <stdio.h>      // to use perror
#include <stdlib.h>     // to use exit

#define WRITE_ERROR -1

int main (int argc, char* argv[]) {

        for (int i = 1; i < argc; i++) {
                // write to stdout
                if(write(1, argv[i], strlen(argv[i])) < 0) {
                        perror("Error in writing to stdout file");
                        exit(WRITE_ERROR);
                }

                // prints sapce between arguments
                if (i != argc - 1) {
                        if(write(1, " ", 1) < 0){
                                perror("Error in writing to stdout file");
                                exit(WRITE_ERROR);
                        }
                }
        }       

        // prints newline at the end (even if no arguments are passed)
        if( write(1, "\n", 1) < 0) {
                perror("Error in writing to stdout file");
                exit(WRITE_ERROR);
        }


        return 0;
}
