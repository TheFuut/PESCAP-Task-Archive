#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

int main(){
    ll n, m; string S, P;
    cin >> n >> m >> S >> P;
    n=S.size(); m=P.size();
    vector<vll> dp(m,vll(2,0)); vll dp2(m,1e18); dp2[0]=0;
    for(int i=0; i<m; i++) for(int j=0; j<2; j++){
        char c=(j==0?'<':'>');
        if(c==P[i]) dp[i][j]=i+1;
        else{
            ll tot=0;
            for(int k=i;k>=1; k--) if(P[k-1]==c){
                if(P.substr(0,k-1)==P.substr(i-k+1,k-1)){tot=k; break;}
            }
            dp[i][j]=tot;
        }
    }
    for(int i=0; i<n; i++){
        vll ndp2(m,1e18);
        for(int j=0; j<m; j++) for(int k=0; k<2; k++) if(dp2[j]!=1e18){
            char c=(k==0?'<':'>');
            if(dp[j][k]<m) ndp2[dp[j][k]]=min(ndp2[dp[j][k]],dp2[j]+(S[i]!=c));
        }
        swap(dp2,ndp2);
    }
    cout << *min_element(dp2.begin(),dp2.end()) << "\n";
}