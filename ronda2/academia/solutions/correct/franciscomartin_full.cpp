#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

int main(){
    ll n;
    cin >> n;
    vpll A(n); set<ll> C;
    for(int i=0; i<n; i++) cin >> A[i].first >> A[i].second;
    sort(A.begin(),A.end(),[&](pll a,pll b){
        if(a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    });
    for(int i=0; i<n; i++){
        auto [a,b]=A[i]; auto it=C.lower_bound(b);
        if(it==C.end()) C.insert(b);
        else C.erase(it), C.insert(b);
    }
    cout << C.size() << "\n";
}