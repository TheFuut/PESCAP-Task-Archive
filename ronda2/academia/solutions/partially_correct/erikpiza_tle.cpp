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

void solve() {
	// LOL?
	int N; cin >> N;
	vector<ii> a(N);
	for(auto&[u,v] : a)
		cin >> u >> v;

	sort(all(a));
	vi dp(N,1);

	fore(i,1,N) {
		int p_ans = 0;
		fore(j,0,i) {
			if(!(a[i].ff > a[j].ff and a[i].ss > a[j].ss))
				continue;
			// cerr << a[j].ff << ' ' << a[j].ss << '\n';
			// cerr << a[i].ff << ' ' << a[i].ss << '\n';
			// cerr << '\n';
			p_ans = max(p_ans,dp[j]);
		}
		dp[i] = p_ans+1;
	}

	cout << *max_element(all(dp)) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// int t; cin >> t;
	// while(t--) 
		solve();
	return 0;
}