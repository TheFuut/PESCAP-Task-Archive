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
	int N, M; cin >> N >> M;
	vector<vector<ii>> g(N);
	bool sub2 = true;
	fore(i,0,M) {
		int T, u, v; cin >> T >> u >> v;
		u--; v--;
		g[u].pb({v, T});
		if(T != 1) 
			g[v].pb({u, T});
		if(T != 2) sub2 = false;
	}

	if(!sub2) {
		bool ans = false;
		fore(i,1,(1<<N)) {
			bool v = true;
			fore(j,0,N) {
				bool cj = i&(1<<j);
				for(auto[k,t]: g[j]) {
					bool ck = i&(1<<k);
					if(t == 1)
						v = v and (!cj or ck);

					if(t == 2)
						v = v and !(cj and ck);

					if(t == 3)
						v = v and (cj or ck);
				}
			}
			ans = ans or v;
		}
		cout << (ans ? "SI\n" : "NO\n");
	} else cout << "SI\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// int t; cin >> t;
	// while(t--) 
		solve();
	return 0;
}