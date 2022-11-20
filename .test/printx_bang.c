#include<stdio.h>

int main() {
    int w, h,i,j;
    scanf("%d %d", &w, &h);
    for(i=1;i<=h;i++){
        for (j = 1; j <= h; j++) {
            if (((i + j < h - w + 2) && (-i + j < -w + 1)) || ((i + j < h - w + 2) && (-i + j > w - 1)) || ((i + j > w + h) && (-i + j > w - 1)) || ((i + j > w + h) && (-i + j < -w + 1)))
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}