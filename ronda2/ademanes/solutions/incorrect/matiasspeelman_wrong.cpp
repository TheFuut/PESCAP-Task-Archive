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

void solve ();

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tests = 1; //cin >> tests;
    for (int test = 1; test <= tests; test++)
        solve();

    return 0;
}

const int MAX_N = 2e5;
int p[MAX_N], sz[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) p[i]=i, sz[i]=1;
}

int find(int u) {
    while (u != p[u]) u =p[u] = p[p[u]];
    return u;
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}

bool same(int u, int v) {
    return find(u) == find(v);
}

int siz(int u) {
    return sz[find(u)];
}

void solve() {
    int n, m; cin >> n >> m;
    string s, p; cin >> s >> p;

    vector<pair<int, int>> ranges;

    for (int i = 0; i+m-1 < n; i++) {
        if (s.substr(i, m) == p) ranges.pb({i, i+m-1});
    }

    vector<int> positions;
    for (int i = 0; i < (int)ranges.size(); i++) {
        auto& [l, r] = ranges[i];
        if (positions.empty() || positions.back() < l) {
            positions.pb(r);
            if (s[r] == '<') s[r] = '>';
            else s[r] == '<';
        }
    }

    ranges.clear(), positions.clear();

    for (int i = 0; i+m-1 < n; i++) {
        if (s.substr(i, m) == p) ranges.pb({i, i+m-1});
    }

    for (int i = 0; i < (int)ranges.size(); i++) {
        auto& [l, r] = ranges[i];
        if (positions.empty() || positions.back() < l) {
            positions.pb(r);
            if (s[r] == '<') s[r] = '>';
            else s[r] == '<';
        }
    }

    cout << positions.size() << "\n";

}