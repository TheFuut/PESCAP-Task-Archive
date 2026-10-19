#include <bits/stdc++.h>
#define fore(v,l,r) for(int v = l; v < (r); v++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
constexpr ll MOD = 1e9+7;
constexpr int INF = 1e9;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vi a(N), b(N);
    for(int& k : a) {cin >> k;k--;}
    for(int& k : b) {cin >> k;k--;}
    assert(K==1);
    int ans = 0;
    fore(i,0,N) ans += __builtin_popcount(a[i]^b[i]);
    cout << ans << '\n';
    return 0;
}