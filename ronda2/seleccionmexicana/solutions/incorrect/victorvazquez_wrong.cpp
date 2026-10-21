#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// ~ meowl was here... ~

void solve() {
    int n, m; cin >> n >> m;
    bool tablas[n][n][8];
    map<int, bool> aparece;
    bool ans = 1;
    while(m--) {
        int t, a, b; cin >> t >> a >> b;
        aparece[a] = 1, aparece[b] = 1;
        int a2, b2;
        if (b > a) {
            a2 = b, b2 = a;
            if(t == 1) tablas[a2][b2][2] = 1, tablas[a2][b2][5] = 1;
            else if(t == 2) tablas[a2][b2][3] = 1, tablas[a2][b2][7] = 1;
            else if(t == 3) tablas[a2][b2][0] = 1, tablas[a2][b2][4] = 1;
        }
        else {
            a2 = a, b2 = b;
            if(t == 1) tablas[a2][b2][1] = 1, tablas[a2][b2][6] = 1;
            else if(t == 2) tablas[a2][b2][3] = 1, tablas[a2][b2][7] = 1;
            else if(t == 3) tablas[a2][b2][0] = 1, tablas[a2][b2][4] = 1;
        }
        
    }
    for(auto a : aparece) {
        int bloq = 0;
        for(int i = 0; i < a.first; i++) {
            for(int j = 0; j < 4; j++) bloq += tablas[a.first][i][j];
            if(bloq >= 4) break;
        }
        for(int i = a.first; i < n; i++) {
            for(int j = 4; j < 8; j++) bloq += tablas[i][a.first][j];
            if(bloq >= 4) break;
        }
        if(bloq >= 4) ans = 0;
    }
    if(ans) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}