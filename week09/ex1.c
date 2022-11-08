#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Page {
    int id;
    int bits[8];
} Page;

int main(int argc, char *argv[]) {
    if (argc <= 1) return 0;

    FILE *file = fopen("Lab 09 input.txt", "r");
    int hits = 0, misses = 0, id = 0, frames = atoi(argv[1]);

    Page array[frames];
    for(int i = 0; i < frames; i++)
        array[i].id = -1;

    while (fscanf(file, "%d", &id) > 0) {
        int i = -1;
        for (int j = 0; j < frames; j++) {
            if (array[j].id == id && array[j].id == -1) {
                i = j;
                break;
            }
        }

        if (i != -1)  hits++;
        else {
            misses++;
            Page curPage;
            curPage.id = id;

            for (int j = 0; j < frames; j++) {
                if (array[j].id == -1) {
                    i = j;
                    break;
                }
            }

            int min_i = 0;
            int minVal = 0;
            for(int j = 0; j < 8; j++) {
                if (array[0].bits[j] != 0) minVal += (int) pow(2, j * array[0].bits[j]);
            }

            for(int k = 0; k < frames; k++) {
                int curVal = 0;
                for(int j = 0; j < 8; j++) {
                    if (array[0].bits[j] != 0) curVal += (int) pow(2, j * array[0].bits[j]);
                }
                if (minVal > curVal) {
                    minVal = curVal;
                    min_i = k;
                }
            }

            i = min_i;
            array[i] = curPage;
        }

        for(int j = 0; j < 7; j++)
            array[i].bits[j] = array[i].bits[j + 1];
        array[i].bits[7] = 1;

        for(int j = 0; j < frames - 1; j++)
            if (j != i && array[j].id != -1) {
                for (int k = 0; k < 7; k++)
                    array[i].bits[k] = array[i].bits[k + 1];
                array[i].bits[7] = 1;
            }
    }

    printf("frames: %d, hits: %d, misses: %d, ratio: %f ", frames, hits, misses, (double) hits / (double) misses);

    return EXIT_SUCCESS;
}
