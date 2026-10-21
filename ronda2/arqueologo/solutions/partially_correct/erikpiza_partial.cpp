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
	if(N==1) {
		cout << a[0] << '\n';
		return;
	}

	vi part, vis(N,0);
	auto dfs = [&](auto& self, int n) -> void {
		vis[n] = 1;
		for(int k : g[n]) if(!vis[k]) {
			part.pb(k);
			self(self, k);
		}
	};
	fore(i,0,N) if(g[i].size()==1) {
		part.pb(i);
		dfs(dfs, i);
	}

	int m; fore(i,0,N) if(part[i] == 0) m = i;
	vll a1, a2;
	fore(i,0,m) a1.pb(a[part[i]]); reverse(all(a1));
	fore(i,m+1,N) a2.pb(a[part[i]]);

	fore(i,1,a1.size()) a1[i] += a1[i-1];
	fore(i,1,a2.size()) a2[i] += a2[i-1];
	ll ans = 0;

	fore(i,0,a1.size()) {
		if(i+1>L) break;
		ll p_ans = a1[i];
		if(2*(i+1)<L && !a2.empty()) p_ans += a2[min(1ULL*L-2*(i+1)-1,1LL*a2.size()-1)];
		ans = max(ans,p_ans);
	}

	fore(i,0,a2.size()) {
		if(i+1>L) break;
		ll p_ans = a2[i];
		if(2*(i+1)<L && !a1.empty()) p_ans += a1[min(1ULL*L-2*(i+1)-1,1LL*a1.size()-1)];
		ans = max(ans,p_ans);
	}

	cout << ans+a[0] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// int t; cin >> t;
	// while(t--) 
		solve();
	return 0;
}