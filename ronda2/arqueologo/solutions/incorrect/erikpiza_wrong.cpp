#include <bits/stdc++.h>
#define fore(v,l,r) for(int v = (l); v < (r); v++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
	int N, L; cin >> N >> L;
	vi a(N); for(int& k : a) cin >> k;

	vector<vi> g(N); vi p(N,0);
	fore(i,0,N-1) {
		int u, v;
		cin >> u >> v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	vi vis(N,0); ll ans = 0; vis[0] = 1;
	auto dfs = [&](auto& self, int n, int d, ll s) -> void {
		ans = max(ans,s);
		if(d == L) return;
		for(int k : g[n]) {
			if(!vis[k]) {
				vis[k] = 1;
				self(self, k, d+1, s+a[k]);
				vis[k] = 0;
			} else self(self, k, d+1, s);
		}
	};
	dfs(dfs, 0, 0, a[0]);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// int t; cin >> t;
	// while(t--) 
		solve();
	return 0;
}