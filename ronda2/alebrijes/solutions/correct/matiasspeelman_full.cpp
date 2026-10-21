#include <bits/stdc++.h>
#include <bit>
#include <numeric>
using namespace std;

using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve ();

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tests = 1; cin >> tests;
    for (int test = 1; test <= tests; test++)
        solve();

    return 0;
}


void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n); for (ll& x : v) cin >> x;
    ll mx = -1;
    for (int i = 0; i < n; i++) {
        if (i != 0) mx = max(mx, v[i]+v[0]);
        if (i != n-1) mx = max(mx, v[i]+v[n-1]);
    }
    cout << ((mx>=k)?"SI":"NO") << "\n";
}