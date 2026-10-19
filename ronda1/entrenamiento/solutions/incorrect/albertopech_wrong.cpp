#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    int cnt = N;
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            cout << cnt << "\n";
        } else {
            int x;
            cin >> x;
            cnt++;
        }
    }
    return 0;
}