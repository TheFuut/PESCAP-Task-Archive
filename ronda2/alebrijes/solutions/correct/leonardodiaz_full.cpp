#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;

        ll maxVal = 0, l , r;
        cin >> l;
        ll input; for(int i = 1 ; i < n - 1 ; i++) {cin >> input; maxVal = max(maxVal, input);}
        cin >> r;

        cout << (maxVal + max(l, r) >= k or l + r >= k ? "SI" : "NO") << "\n";
    }
    return 0;
}