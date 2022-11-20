#include<iostream>
using namespace std;
typedef long long ll;

ll solve(int now) {
    ll result = 0;
    int branch = (now%2 == 0 ? 2 : 3);
    for (int i = 1;i <= branch;i++) {
        int next;
        cin >> next;
        if (next != 0) {
            result += abs(now-next) + solve(next);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int head;
    cin >> head;
    cout << solve(head) << '\n';
    return 0;
}