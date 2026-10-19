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

    int tests = 1; //cin >> tests;
    for (int test = 1; test <= tests; test++)
        solve();
 
	return 0;
}

void solve() {
    int n, k; cin >> n >> k;
    vpi a(n, {0, 0}), b(n, {0, 0});

    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        switch (in)
        {
        case 2:
            a[i].first = 1;
            break;
        case 3:
            a[i].second = 1;
            break;
        case 4:
            a[i].first = a[i].second = 1;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        switch (in)
        {
        case 2:
            b[i].first = 1;
            break;
        case 3:
            b[i].second = 1;
            break;
        case 4:
            b[i].first = b[i].second = 1;
            break;
        }
    }

    pii op = {0, 0};

    int res = 0;

    vpi ops(n, {0, 0});
    for (int i = 0; i < n; i++) {
        op.first^=ops[i].first; 
        op.second^=ops[i].second;

        a[i].first^=op.first;
        a[i].second^=op.second;

        res+=a[i].first^b[i].first;
        res+=a[i].second^b[i].second;

        op.first^=a[i].first^b[i].first;
        op.second^=a[i].second^b[i].second;

        if (i+k < n) {
            ops[i+k].first^=a[i].first^b[i].first;
            ops[i+k].second^=a[i].second^b[i].second;
        }
    }

    if (a != b) {
        cout << -1 << endl;
        return;
    }

    cout << res << endl;
}