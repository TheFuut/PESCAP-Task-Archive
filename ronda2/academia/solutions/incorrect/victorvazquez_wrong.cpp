#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// ~ meowl was here... ~

void solve() {
    ull n, m; cin >> n >> m;
    string s, p;
    cin >> s >> p;
    ull ans = 0;
    short match[n];
    bool run = 1;
    while(run) {
        fill_n(match, n, 0);
        for(int i = 0; i < n - m + 1; i++) {
            bool equal = 1;
            for(int j = 0; j < m; j++) {
                if(p[j] != s[i + j]) equal = 0;
            }
            if(equal) {
                for(int j = 0; j < m; j++) match[i + j]++;
            
            }
        }
        int mayor = 0, mayor_n = -1;
        for(int i = 0; i < n; i++) {
            if(match[i] > mayor) mayor = match[i], mayor_n = i;           
        }
        if(mayor_n == -1) {
            run = 0; 
        } else {
            if(s[mayor_n] == '<') s[mayor_n] = '>';
            else s[mayor_n] = '<';
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}