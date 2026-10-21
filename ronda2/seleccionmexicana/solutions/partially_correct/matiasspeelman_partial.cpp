#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 3e18;

#define pb push_back
#define all(x) (x).begin(), (x).end()

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m ; i++ ){
         int y, a, b; cin >> y >> a >> b;
         a--, b--;
         adj[a].pb(b);
         adj[b].pb(a);
    }

    cout << "SI\n";

    return 0;
}