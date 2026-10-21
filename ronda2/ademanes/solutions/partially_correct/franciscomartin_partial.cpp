#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

int main(){
    ll n, m, ans=0; string S, P;
    cin >> n >> m >> S >> P;
    for(int i=0; i<n-m+1; i++){
        if(S.substr(i,m)==P) ans++, i+=m-1;
    }
    cout << ans << "\n";
}