#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

void Solve(){
    ll n, k, maxi=0;
    cin >> n >> k;
    vll A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    if(n==1){cout << "SI\n"; return;}
    for(int i=0; i<n-1; i++) maxi=max(maxi,A[i]+A[i+1]);
    cout << (maxi>=k?"SI":"NO") << "\n";
}

int main(){
    ll tt;
    cin >> tt;
    while(tt--) Solve();
}