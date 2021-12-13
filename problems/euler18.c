#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE 500
#define MAX(x, y) (x < y) ? y : x

typedef struct file_size{
    int line_count;
    int longest_line;
} file_size;


void die(char *message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

file_size get_file_size(FILE *fp) {
    char buff[MAX_LINE];
    file_size fs;
    fs.line_count = 0;
    fs.longest_line = 0;
    while( fgets (buff, MAX_LINE, fp) != NULL) {
        fs.line_count++;
        int x = strlen(buff);
        fs.longest_line = MAX(fs.longest_line, x);
    }
    rewind(fp);
    return fs;
}

char** read_file(FILE *fp, file_size fs) {
    char buff[fs.longest_line + 1];
    char **list = malloc( sizeof(char*) * (fs.line_count) );
    if(list == NULL)
        die("failed to allocate lines array");
    int index = 0;
    while(fgets (buff, MAX_LINE, fp) != NULL) {
        list[index] = malloc(fs.longest_line);
        strcpy(list[index], buff);
        index++;
    }
    rewind(fp);
    return list;
}

int *line_to_array(char *line, int size) {
    int *output = malloc(sizeof(int) * size);
    int current = 0;

    char *token = strtok(line, " ");
    while(token != NULL) {
        output[current++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return output;
}

int main(int argc, char *argv[]) {
    if(argc != 2)
        die("USAGE: euler18 <pyramid file>\n File should be pyramid of numbers");
    FILE *fptr = fopen(argv[1], "r");

    file_size size = get_file_size(fptr);
    char **file = read_file(fptr, size);

    int count = size.line_count;
    int *line = line_to_array(file[count - 1], count);
    count--;

    while(count != 0) {
        int *next = line_to_array(file[count - 1], count);
        for(int i = 0; i < count; i++) {
            line[i] = ( next[i] + (MAX(line[i], line[i+1])) );
        }
        count--;
    }

    printf("%d\n", line[0]);
    rewind(fptr);
}

/*
 * The problem defined stated that there would be another problem with 100 levels to the triangle, so I'm considering
 * taking the extra time to figure out how to take in a file of the triangle and building the triangle with it, using the code from
 * problem 13.
 *
 *  Best method I could come up with was working from the bottom up. adding the max.
 *
 */