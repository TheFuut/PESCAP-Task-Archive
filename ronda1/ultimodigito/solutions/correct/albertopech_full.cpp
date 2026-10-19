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

const int ciclo[12] = {7, 5, 7, 2, 1, 2, 1, 8, 4, 8, 4, 5};

void solve() {
    ll m; cin >> m;
    cout << ciclo[(m - 1) % 12] << '\n';
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