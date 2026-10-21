#include <bits/stdc++.h>
#define fore(v,l,r) for(int v = (l); v < (r); v++)
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

void solve() {
	// La mejor persona que uno puede ser es la persona que intenta hacerse cada vez un poco mejor e impulsa a los demas a tambien intentar.
	int N, M; cin >> N >> M;
	string A, B; cin >> A >> B;
	assert(N <= 20);

	auto ch = [&](int i) -> void {
		A[i] ^= ('<' xor '>');
	};

	int ans = N;
	fore(i,0,(1<<N)) {
		bool val = true;
		fore(j,0,N) if(i&(1<<j)) ch(j);
		
		fore(j,0,N-M+1) {
			bool isS = true;
			fore(k,0,M) if(A[j+k]!=B[k])
				isS = false;
			val = val && !isS;
		}
		if(val) ans = min(ans,__builtin_popcount(i));
		fore(j,0,N) if(i&(1<<j)) ch(j);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// int t; cin >> t;
	// while(t--) 
		solve();
	return 0;
}