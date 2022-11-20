#include<stdio.h>
int N;

void solve(int *A, int *B, int *op_cnt);

int main(){
    int A[1<<17] = {0};
    int B[1<<17] = {0};
    int op_cnt = 0;

    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i<N; i++)
        scanf("%d", &B[i]);

    solve(A, B, &op_cnt);
    printf("%d\n", op_cnt);
    for(int i = 0; i<N; i++)
        printf("%d ", A[i]);
}

//

void solve(int *A, int *B, int *op_cnt){
    for (int i = 0;i < N;i++) {
        if (A[i] < B[i]) {
            (*op_cnt)++;
            int tmp = A[i];
            A[i] = B[i];
            B[i] = tmp;
        }
    }
}