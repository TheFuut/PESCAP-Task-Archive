#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 3e18;

#define pb push_back
#define all(x) (x).begin(), (x).end()

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, l; cin >> n >> l;
    vector<ll> v(n); for (ll& x : v) cin >> x;

    vector<vector<ll>> adj(n);
    for (ll i = 1; i < n; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b); 
        adj[b].push_back(a);
    }

    vector<ll> subtree(n, 1);

    auto dfs0 = [&](auto&& self, ll u, ll p) -> void {
        for (ll& v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            subtree[u]+=subtree[v];
        }
    };  

    dfs0(dfs0, 0, -1);

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(l + 1, vector<ll>(2, -INF)));
    
    auto dfs1 = [&](auto&& self, ll u, ll p) -> void {
        dp[u][0][0] = v[u];
        dp[u][0][1] = v[u];

        ll sz = 1;

        for (ll child : adj[u]) {
            if (child == p) continue;
            
            self(self, child, u); 

            vector<vector<ll>> next_dp(l + 1, vector<ll>(2, -INF));

            for (ll i = 0; i <= min(l, 2*sz); i++) {
                for (ll j = 0; j <= min(l, 2*subtree[child]); j++) {   

                    if (i + j + 2 <= l) {
                        if (dp[u][i][0] != -INF && dp[child][j][0] != -INF)
                            next_dp[i+j+2][0] = max(next_dp[i+j+2][0], dp[u][i][0] + dp[child][j][0]);
                        
                        if (dp[u][i][1] != -INF && dp[child][j][0] != -INF)
                            next_dp[i+j+2][1] = max(next_dp[i+j+2][1], dp[u][i][1] + dp[child][j][0]);
                    }

                    if (i + j + 1 <= l) {
                        if (dp[u][i][0] != -INF && dp[child][j][1] != -INF)
                            next_dp[i+j+1][1] = max(next_dp[i+j + 1][1], dp[u][i][0] + dp[child][j][1]);
                    }
                }
            }

            
            for (ll i = 0; i <= l; i++) {
                next_dp[i][0] = max(next_dp[i][0], dp[u][i][0]);
                next_dp[i][1] = max(next_dp[i][1], dp[u][i][1]);
            }

            dp[u] = next_dp;

            sz += subtree[child];
        }
    };

    dfs1(dfs1, 0, -1);

    ll ans = 0;
    for (ll i = 0; i <= l; i++) {
        ans = max({ans, dp[0][i][0], dp[0][i][1]});
    }

    cout << ans << "\n";

    return 0;
}