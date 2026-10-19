#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    
    vector<int>a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(5);
    a.push_back(7);
    ///
    a.push_back(2);
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    //
    a.push_back(8);
    a.push_back(4);
    a.push_back(8);
    a.push_back(4);
    
    cout<<a[n%12]<<'\n';
    
}

int main() {
    int t;
    cin>>t;
    
    while(t--)solve();
    
    return 0;
}