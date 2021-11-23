#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE 500

void die(char *message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

int line_count(FILE *fp) {
    char buff[MAX_LINE];
    int count = 0;
    if(fp == NULL) {
        die("Line_count, file not found");
    }
    while( fgets (buff, MAX_LINE, fp) != NULL) {
        count++;
    }
    rewind(fp);
    return count;
}

char** get_lines(FILE *fp, int lines) {
    char buff[MAX_LINE];
    char **list = malloc( sizeof(char*) * (lines) );
    if(list == NULL)
        die("failed to allocate lines array");
    int index = 0;
    if(fp == NULL)
        die("get_lines file not found");
    while(fgets (buff, MAX_LINE, fp) != NULL) {
        list[index] = malloc(strlen(buff) + 1);
        strcpy(list[index], buff);
        index++;
    }
    rewind(fp);
    return list;
}

long last_ten(long long n) {

}

int main(int argc, char *argv[]) {
    if(argc < 2)
        die("USAGE: euler13 <fileName>\n File should include at least one 10+digit number, and will print the first 10 digits of the sum of the numbers. \n Each number should be on a new line.");

    char *file = argv[1];

    FILE *fptr = fopen(file, "r");

    if (fptr == NULL) {
        die("File failed to load");
    }

    int lines_count = line_count(fptr);
    if(lines_count == 0)
        die("failed to get line count");

    char** lines = get_lines(fptr, lines_count);

    long long x = atoll(lines[0]);
    printf("%lld\n", x);
    fclose(fptr);
    return 0;
}

/*
 *  I wanted to make it easy to add and remove numbers from the list, so I started by figuring out how to work with files in C.
 *  That was a terrible idea....
 *  but it's working now, and now I'm looking at starting with a single number, and returning the first 10 digits, before
 *  moving onto sum them up, and do the same.
 */