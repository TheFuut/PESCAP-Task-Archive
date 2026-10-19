#include <bits/stdc++.h>
using namespace std;

template<typename T>
using vec = vector<T>;

template<typename T>
using matrix = vec<vec<T>>;

template<typename T>
inline int sz(const T& x) { return (int)x.size(); }

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vec<int>;
using vll = vec<ll>;
using vs = vec<string>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

constexpr ll MOD = 1'000'000'007LL;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define fore(i,a,b) for (int i = (a); i < (b); i++)
#define TEST_CASES 1

void solve() {
    ll m; cin >> m;
    vi v = {8, 4, 5};
    for (int i = 2; i < m + 2; i++) {
        int x = (v[i] + v[i-1] + v[i-2]);
        x = (x + x) % 9;
        v.pb(x);
    }
    cout << v[sz(v)-1] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
#if TEST_CASES
    int t; cin >> t;
    while (t--) solve();
#else
    solve();
#endif
}