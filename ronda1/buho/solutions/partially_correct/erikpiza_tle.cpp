#include <bits/stdc++.h>
#define fore(v,l,r) for(int v = l; v < (r); v++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
constexpr ll MOD = 1e9+7;
constexpr int INF = 1e9;

struct DSU {
    vi dsu, sz;
    int comps;

    DSU(int n) {
        dsu.resize(n); iota(all(dsu),0);
        sz.resize(n,1); comps = n;
    }

    int find(int n) {
        if(dsu[n] == n) return n;
        return dsu[n] = find(dsu[n]);
    }

    bool merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(sz[pu]<sz[pv]) swap(pu,pv);
        comps--;
        dsu[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;

    vector<tuple<int,int,int>> edg(M);
    for(auto&[w,u,v] : edg) cin >> u >> v >> w;
    sort(all(edg));

    DSU tr(N);
    vector<vector<pii>> g(N);
    for(auto[w,u,v] : edg) {
        u--; v--;
        if(tr.merge(u,v)) {
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        if(tr.comps == 1) break;
    }

    while(Q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        queue<int> bfs; bfs.push(a);
        vi ans(N,0);
        while(!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            for(auto[v,w] : g[u]) {
                if(ans[v] != 0) continue;
                ans[v] = max(ans[u],w);
                bfs.push(v);
            }
        }
        cout << ans[b] << '\n';
    }
    return 0;
}