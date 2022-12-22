#include<iostream>
#include<set>
using namespace std;

typedef struct matrix {
    int arr[2][2];
    matrix() {
        memset(arr, 0, sizeof(arr));
    }
    matrix operator* (const matrix &m) {
        matrix result;
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                for (int k = 0;k < 2;k++) {
                    result.arr[i][j] += arr[i][k] * m.arr[k][j];
                }
            }
        }
        return result;
    }
    void print() {
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
} Matrix;

int main() {
    Matrix m, a, b;
    a.arr[0][0] = 1, a.arr[0][1] = 1;
    a.arr[1][0] = 1, a.arr[1][1] = 1;

    b.arr[0][0] = 1, b.arr[0][1] = 0;
    b.arr[1][0] = 0, b.arr[1][1] = 1;
    m = a * b;
    m.print();
    return 0;
} 