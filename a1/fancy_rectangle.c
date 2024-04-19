#include "stdio.h"
#include "stdlib.h"

/*
 * PrintFancyRectangle
 * This function prints a fancy rectangle.
 */

void PrintFancyRectangles(int width, int height, char symbol, int fill){

    for (int i = 0; i < width-1; i++) {
        printf("%c",symbol);
    }
    printf("%c\n",symbol);

    int gap = width-2;

    if (fill == 0) {
        for (int i = 0; i < height - 2; i++) {
            printf("%c", symbol);
            printf("%*s", gap, "");
            printf("%c\n", symbol);
        }
    } else{
        for (int i = 0; i < height-2; ++i) {
            for (int j = 0; j < width ; ++j) {
                printf("%c",symbol);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < width-1; i++) {
        printf("%c",symbol);
    }
    printf("%c\n",symbol);


}

int main(){

    PrintFancyRectangles(5,4,'+',0);

}
