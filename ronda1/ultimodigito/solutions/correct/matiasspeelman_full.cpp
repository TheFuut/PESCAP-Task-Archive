#include <bits/stdc++.h>
using namespace std;
 
#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0)
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;
 
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
 
#define all(x) (x).begin(), (x).end()
#define read(v) for(auto& x : v) cin >> x
#define pb push_back
#define rs resize
 
void solve();

signed main() {
    fastIO;

    int tests = 1; cin >> tests;
    for (int test = 1; test <= tests; test++)
        solve();
 
	return 0;
}

void solve() {
    ll m; cin >> m;
    if (m % 12 == 1) cout << 7 << endl;
    if (m % 12 == 2) cout << 5 << endl;
    if (m % 12 == 3) cout << 7 << endl;
    if (m % 12 == 4) cout << 2 << endl;
    if (m % 12 == 5) cout << 1 << endl;
    if (m % 12 == 6) cout << 2 << endl;
    if (m % 12 == 7) cout << 1 << endl;
    if (m % 12 == 8) cout << 8 << endl;
    if (m % 12 == 9) cout << 4 << endl;
    if (m % 12 == 10) cout << 8 << endl;
    if (m % 12 == 11) cout << 4 << endl;
    if (m % 12 == 0) cout << 5 << endl;
}

// 8 4 5 7 5 7 2 1 2 1 8 4 8 4 5