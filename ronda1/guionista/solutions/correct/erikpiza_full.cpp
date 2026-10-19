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
    vi a(N), b(N), e(N,0);
    for(int& k : a) {cin >> k;k--;}
    for(int& k : b) {cin >> k;k--;}

    // En vez de alterar el subarreglo entero, mejor mantengo el estado alterado LOL
    int e1=0, e2=0,
        ans = 0;
    fore(i,0,N-K+1) {
        if((e1^(a[i]&1)) != (b[i]&1)) {
            ans++;
            e1 ^= 1;
            e[i+K-1] |= 1;
        }
        
        if((e2^(a[i]&2)) != (b[i]&2)) {
            ans++;
            e2 ^= 2;
            e[i+K-1] |= 2;
        }
        e1^=(e[i]&1);
        e2^=(e[i]&2);
    }
    fore(i,N-K+1,N) {
        if((a[i]^e1^e2)!=b[i]) ans = -1;
        e1^=(e[i]&1);
        e2^=(e[i]&2);
    }

    cout << ans << '\n';
    return 0;
}