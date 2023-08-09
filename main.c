#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *line, *token, *first_token, *second_token;
    ssize_t size = 0, gerror, i;
    int count;
    
    while (1) {
        i = 0;
        line = NULL;
        
        write(1, "$ ", 2);
        
        gerror = getline(&line, &size, stdin);
        
        if (gerror == -1) {
            free(line);
            exit(0);
        }
        
        
        token = strtok(line, "/");
        count = 0;
        while (token != NULL) {
            if (count == 0) {
                first_token = token;
            } else if (count == 1) {
                second_token = token;
        }
	     count++;
                token = strtok(NULL, "/");
	}
	    if (count == 1 || count > 2)
		     printf("%s: No such file or directory\n", argv[0]);
        
	    if (count == 2 && strcmp(first_token,"bin")== 0)
	    {
		    command_type(second_token);
	    }
        free(line);
    }
    
    return 0;
}

