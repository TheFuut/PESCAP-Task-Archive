#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const ll MAXN = 1005;

vector<vll> dp0(MAXN), dp1(MAXN), g(MAXN); vll val(MAXN); ll n, l;
void dfs(ll v, ll p) {
    dp0[v].push_back(val[v]); dp1[v].push_back(val[v]);
    for(auto u:g[v]) if(u!=p){
        dfs(u, v); ll sz=min(l,(ll)dp0[v].size()+(ll)dp0[u].size()+1);
        vll ndp0(sz+1,-1e18), ndp1(sz+1,-1e18);
        for(int i=0; i<(ll)dp0[v].size(); i++) ndp0[i]=dp0[v][i], ndp1[i]=dp1[v][i];
        for(int i=0; i<(ll)dp0[v].size(); i++) for(int j=0; j<(ll)dp0[u].size(); j++){
            if(i+j+2<=sz){
                ndp0[i+j+2]=max(ndp0[i+j+2],dp0[v][i]+dp0[u][j]);
                ndp1[i+j+2]=max(ndp1[i+j+2],dp1[v][i]+dp0[u][j]);
            }
            if(i+j+1<=sz) ndp1[i+j+1]=max(ndp1[i+j+1],dp0[v][i]+dp1[u][j]);
        }
        swap(dp0[v],ndp0); swap(dp1[v],ndp1);
    }
}

int main(){
    ll a, b, ans=-1e18;
    cin >> n >> l;
    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1,-1);
    ans=max(ans,*max_element(dp0[1].begin(),dp0[1].end()));
    ans=max(ans,*max_element(dp1[1].begin(),dp1[1].end()));
    cout << ans << "\n";
}