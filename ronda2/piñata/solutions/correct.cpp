#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, k; cin >> n >> k;
    long long sum = 0;
    while(n--) {
        int x; cin >> x, sum += x;
    }
    if (sum >= k) cout << "Dulces para todos";
    else cout << "Sin dulces";
}