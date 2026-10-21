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

    int tests = 1; //cin >> tests;
    for (int test = 1; test <= tests; test++)
        solve();

    return 0;
}


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) cin >> a >> b;
    
    sort(all(v), [](const pair<int,int>& p1, const pair<int,int>& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    });
    
    vector<int> tails;
    for (auto [x, y] : v) {
        auto it = lower_bound(tails.begin(), tails.end(), y);
        if (it == tails.end()) tails.push_back(y);
        else *it = y;
    }

    cout << tails.size() << "\n";
}