#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;

#define pb push_back
#define all(x) (x).begin(), (x).end()

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l; cin >> n >> l;
    vector<int> v(n); for (int& x : v) cin >> x;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b); 
        adj[b].push_back(a);
    }

    vector<int> subtree(n, 1);

    auto dfs0 = [&](auto&& self, int u, int p) -> void {
        for (int& v : adj[u]) {
            if (v == p) continue;
            subtree[u]+=subtree[v];
        }
    };  

    dfs0(dfs0, 0, -1);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(l + 1, vector<int>(2, -INF)));
    
    auto dfs1 = [&](auto&& self, int u, int p) -> void {
        dp[u][0][0] = v[u];
        dp[u][0][1] = v[u];

        for (int child : adj[u]) {
            if (child == p) continue;
            
            self(self, child, u); 

            vector<vector<int>> next_dp(l + 1, vector<int>(2, -INF));

            for (int i = 0; i <= 2*subtree[u]; i++) {
                for (int j = 0; j <= 2*subtree[child]; j++) {   

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

            
            for (int i = 0; i <= l; i++) {
                next_dp[i][0] = max(next_dp[i][0], dp[u][i][0]);
                next_dp[i][1] = max(next_dp[i][1], dp[u][i][1]);
            }

            dp[u] = next_dp;
        }
    };

    dfs1(dfs1, 0, -1);

    int ans = 0;
    for (int i = 0; i <= l; i++) {
        ans = max({ans, dp[0][i][0], dp[0][i][1]});
    }

    cout << ans << "\n";

    return 0;
}