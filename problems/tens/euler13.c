#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE 500
#define NEWLINE 1
#define MAX(x, y) (x < y) ? y : x
#define REAL_NUMBER(x) ( 0 > x || x > 9 ) ? 1 : 0

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
        int x = strlen(buff) - NEWLINE;
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

int** parse_file(FILE *fp, file_size fs) {
    char **lines = read_file(fp, fs);
    if(lines == NULL)
        die("unable to get lines from file");
    int **numbers = malloc( sizeof(int*) * fs.line_count );
    for(int y = 0; y < fs.line_count; y++) {
        numbers[y] = malloc( sizeof(int*) * fs.longest_line);
        int length = strlen(lines[y]) - NEWLINE;
        int difference = fs.longest_line - length;
        for(int x= 0; x < difference; x++) {
            numbers[y][x] = 0;
        }
        for(int x = 0; x < length; x++) {
            int temp = lines[y][x] - '0';
            numbers[y][x + difference] = ( REAL_NUMBER(temp) ) ? 0 : temp;
        }

    }
    free(lines);
    return numbers;
}



int main(int argc, char *argv[]) {
    if(argc < 2)
        die("USAGE: euler13 <fileName>\n File should include at least one 10+digit number, and will print the first 10 digits of the sum of the numbers. \n Each number should be on a new line and you should have a new line at the end of the file.");

    char *file = argv[1];

    FILE *fptr = fopen(file, "r");
    if(fptr == NULL)
        die("Failed to load file");

    file_size fs = get_file_size(fptr);

    if(fs.line_count == 0)
        die("failed to get line count, or file is empty.");

    printf("lines: %d length: %d \n", fs.line_count, fs.longest_line);

    int **numbers = parse_file(fptr, fs);
    int result[fs.longest_line];
    int carry = 0;
    for(int column = fs.longest_line - 1; column >= 0; column--) {
        int sum = 0;
        sum += carry;
        for(int row = 0; row < fs.line_count; row++) {
            sum += numbers[row][column];
        }
        if(column != 0) {
            result[column] = (sum % 10);
            carry = (sum / 10);
        }
        else {
            result[column] = sum;
        }
    }
    for(int i = 0; i < fs.longest_line; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    free(numbers);

    fclose(fptr);
    return 0;
}

/*
 *  I wanted to make it easy to add and remove numbers from the list, so I started by figuring out how to work with files in C.
 *  That was a terrible idea....
 *  but it's working now, and now I'm looking at starting with a single number, and returning the first 10 digits, before
 *  moving onto sum them up, and do the same.
 *
 *  So Working with a number...
 *  12345
 *  if we want five, we can divide by 10, and take the remainder. or mod 10
 *  135,740,250
 *
 *  I'm probably spending far too long making this more than it needed to be. At this point you can have as many numbers
 *  as you want, but if you want to work with smaller numbers, it has to be pre-pended with zeroes, because I don't
 *  populate the numbers correctly.
 *
 *  Now we do.
 *
 *  Now after all that, we should actually solve the problem, and sum the numbers.
 *
 *  I took too much time over-engeneering it for what it needed to be.
 *  Large part of that, was this is meant to help me learn, and so I went a route that would require me to learn more.
 *  I also wanted to make sure my solution could be used over again in the future, even if it never needs to be.
*/
