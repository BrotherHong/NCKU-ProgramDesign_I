#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}

//

void sort_section(int *ptr, int *qtr) {
    if (ptr > qtr) {
        // swap
        int *tmp = ptr;
        ptr = qtr;
        qtr = tmp;
    }
    int N = qtr - ptr;
    for (int i = N;i > 0;i--) {
        for (int j = 0;j+1 <= i;j++) {
            if (ptr[j] > ptr[j+1]) {
                int tmp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = tmp;
            }
        }
        // print
        for (int j = 0;j <= N;j++) {
            printf("%d ", ptr[j]);
        }
        printf("\n");
    }
}
