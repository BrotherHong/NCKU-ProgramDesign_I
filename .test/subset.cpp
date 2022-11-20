#include<iostream>
using namespace std;

char S[26];

void printAllSubset(int n) {
    for (int b = 0;b < (1 << n);b++) {
        cout << "[";
        for (int k = 0;k < n;k++) {
            if (b & (1 << k)) {
                cout << S[k];
            }
        }
        cout << "]\n";
    }
}

int main() {
    // initilize set
    for (int i = 0;i < 26;i++) {
        S[i] = i + 'A';
    }
    int N;
    cin >> N;
    printAllSubset(N);
    return 0;
}