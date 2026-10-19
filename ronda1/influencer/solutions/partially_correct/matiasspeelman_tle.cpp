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
using vpll = vector<pll>;
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

struct MaxSeg {
    ll N;
    vpll tree;

    MaxSeg(vll &v) : N(v.size()), tree(2*v.size(), {0, 0}) {
        for (ll i = 0; i < N; i++) 
            tree[i+N] = {i, v[i]};
        for (ll i = N-1; i > 0; i--) {
            if (tree[2*i].second > tree[2*i+1].second)
                tree[i] = tree[2*i];
            else if (tree[2*i].second < tree[2*i+1].second)
                tree[i] = tree[2*i+1];
            else
                tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }

    void update(ll pos, ll val) {
        for (tree[pos+=N].second=val; pos>>=1;)
            if (tree[2*pos].second > tree[2*pos+1].second)
                tree[pos] = tree[2*pos];
            else if (tree[2*pos].second < tree[2*pos+1].second)
                tree[pos] = tree[2*pos+1];
            else
                tree[pos] = min(tree[2*pos], tree[2*pos+1]);   
    }

    pll query() {
        return tree[1];}

};

ll n;

ll to_node(ll x, ll y) {
    return x*n+y;}

pll to_coords(ll node) {
    return {node/n, node%n};}

const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};

void solve() {
    cin >> n;

    vvll v(n, vll (n));
    for (auto& _:v) read(_);

    vll _(n*n);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            _[to_node(i, j)] = v[i][j];
            for (ll k = 0; k < 4; k++) {
                ll nx = i+dx[k];
                ll ny = j+dy[k];
                if (nx == -1 || nx == n || ny == -1 || ny == n) continue;
                _[to_node(i, j)]+=v[nx][ny];
            } 
        }
    }

    MaxSeg st(_);

    ll res1 = 0, res2 = 0;
    ll turn = 1;

    while (st.query().second != 0) {

        auto [pos, sum] = st.query();

        if (turn&1) res1 += sum;
        else res2 += sum;
        turn++;

        auto [x, y] = to_coords(pos);

        vector<pii> removed;
        removed.pb({x, y});

        for (ll k = 0; k < 4; k++) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            removed.pb({nx, ny});
        }

        set<ll> affected;

        for (auto [a, b] : removed) {

            affected.insert(to_node(a, b));

            for (ll k = 0; k < 4; k++) {
                ll nx = a + dx[k];
                ll ny = b + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                affected.insert(to_node(nx, ny));
            }
        }

        for (auto [a, b] : removed) {
            v[a][b] = 0;
            st.update(to_node(a, b), 0);
        }

        for (ll node : affected) {

            auto [i, j] = to_coords(node);

            if (v[i][j] == 0) {
                st.update(node, 0);
                continue;
            }

            ll cur = v[i][j];

            for (ll k = 0; k < 4; k++) {
                ll nx = i + dx[k];
                ll ny = j + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                cur += v[nx][ny];
            }

            st.update(node, cur);
        }
    }

    cout << res1 << " " << res2 << endl;

}