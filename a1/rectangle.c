#include "stdio.h"
#include "stdlib.h"

/*
 * Print Rectangles
 * This function prints an empty rectangle of the specified width and height.
 */

void PrintRectangle(int width, int height) {
    for (int i = 0; i < width-1; i++) {
        printf("-");
    }
    printf("-\n");

    int gap = width-2;
    for (int i = 0; i < height-2; i++) {
        printf("-");
        printf("%*s",gap,"");
        printf("-\n");
    }

    for (int i = 0; i < width-1; i++) {
        printf("-");
    }
    printf("-\n");
}


int main(){

    PrintRectangle(6,3);

}