#include <bits/stdc++.h>
#include <bit>
#include <numeric>
#include <string>
using namespace std;

using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

#define all(x) (x).begin(), (x).end()
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        ll A[n];
        for (int i = 0; i < n; i++) cin >> A[i];
        ll mx = 0;
        for (int i = 0; i < n-1; i++) mx = max(mx, A[i] + A[i+1]);
        if (mx >= k) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}