#include <stdio.h>
#include <stdlib.h>

long get_paths(int size) {
    long grid[size + 1][size + 1];

    // Set the corners
    for(int i = 0; i < size + 1; i++) {
        grid[0][i] = 1;
        grid[i][0] = 1;
    }

    for(int col = 1; col < size + 1; col++) {
        for(int row = 1; row < size + 1; row++) {
            grid[col][row] = ( grid[col - 1][row] + grid[col][row - 1] );
            printf("%ld    ", grid[col][row]);
        }
        printf("\n");
    }
    return grid[size+1][size+1];
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("USAGE: euler15 <square grid size>");
        exit(1);
    }
    int size = atoi(argv[1]);

    long paths = get_paths(size);

    printf("%ld\n", paths);

    return 0;
}

/*
 *
 * While struggling to consider how I would walk through 2x2 grid to find a solution, I stumbled across
 * A solution that would involve a pascals triangle, which should give the correct answer.
 * Using the grid below I need to figure out how one would go about adding the edges next to
 * each grid space to get the current number of paths to get there.
 *
 *      1  1  1
        1  2  3
        1  3  *
 *
 *
 *      0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9
 *
 *   0   1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1
 *   1   1  2  3  4  5  6  7  8  9  *  *  *  *  *  *  *  *  *  *  *
 *   2   1  3  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   3   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   4   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   5   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   6   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   7   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   8   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   9   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   0   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   1   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   2   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   3   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   4   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   5   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   6   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   7   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   8   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *   9   1  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 *
 */