#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5;
const int logn = 20;

int con = 0;
vector<int> inn, oout, dep;
vector<int> dsu;
vector<vector<pair<int, int>>> bl(mxn, vector<pair<int, int>>(logn));
vector<vector<pair<int, int>>> adj;

int pa(int a) {
    if (dsu[a] == a) return a;
    return dsu[a] = pa(dsu[a]);
}

void dfs(int v, int pad, int pes, int de) {
    //cout << v << " " << pad << '\n';
    inn[v] = con;
    //dep[v] = de;
    con ++;
    bl[v][0] = {pad, pes};
    for (int t1 = 1; t1 < logn; t1 ++) {
        bl[v][t1].first = bl[bl[v][t1-1].first][t1-1].first; 
        bl[v][t1].second = max(bl[bl[v][t1-1].first][t1-1].second, bl[v][t1-1].second); 
    }
    for (pair<int, int> &hi: adj[v]) {
        if (hi.first == pad) continue;
        dfs(hi.first, v, hi.second, de + 1);
    }
    oout[v] = con;
    con ++;
    return ;
}

int anc(int ance, int hij) {
    if ((inn[ance] <= inn[hij]) && (oout[hij] <= oout[ance])) {
        return 1;
    } else {
        return 0;
    }
}

int sub(int a, int su) {
    int re = 0;
    for (int t1 = 0; t1 < logn; t1 ++) {
        if ((1ll<<t1)&su) {
            re = max(re, bl[a][t1].second);
            a = bl[a][t1].first;
        }
    }
    return re;
}

int lca(int a, int b) {
    int res = 0;
    if (!anc(a, b)) {
        for (int t1 = logn-1; t1 >= 0; t1 --) {
            if (anc(bl[a][t1].first, b)) {
            } else {
                res = max(res, bl[a][t1].second);
                a = bl[a][t1].first;
            }
        }
        res = max(res, bl[a][0].second);
    }
    if (!anc(b, a)) {
        for (int t1 = logn-1; t1 >= 0; t1 --) {
            if (anc(bl[b][t1].first, a)) {
            } else {
                res = max(res, bl[b][t1].second);
                b = bl[b][t1].first;
            }
        }
        res = max(res, bl[b][0].second);
    }
    return res;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    adj.resize(n);
    inn.resize(n);
    //dep.resize(n);
    oout.resize(n);
    if (m == n - 1) {
        for (int t1 = 0; t1 < m; t1 ++) {
            int a, b, c;
            cin >> a >> b >> c;
            a --; b --;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
    } else {

        dsu.resize(n);
        for (int t1 = 0; t1 < n; t1 ++) {
            dsu[t1] = t1;
        }
        vector<vector<int>> aris(m);
        for (int t1 = 0; t1 < m; t1 ++) {
            int a, b, c;
            cin >> a >> b >> c;
            a --; b --;
            aris[t1] = {c, a, b};
        }
        sort(aris.begin(), aris.end());
        int comp = n;
        int piv = 0;
        while (comp > 1) {
            int c = aris[piv][0];
            int a = aris[piv][1], b = aris[piv][2];
            int paa = pa(a), pab = pa(b);
            if (paa != pab) {
                if (paa > pab) swap(paa, pab);
                comp --;
                dsu[pab] = paa;
                adj[a].push_back({b, c});
                adj[b].push_back({a, c});
            }
            piv ++;
        }
    }
        //for (int t1 = 0; t1 < n; t1 ++) {
            //    for (auto pa: adj[t1]) {
                //        cout << t1 << " " << pa.first << ": " << pa.second << '\n';
    //    }
    //}
    for (int t1 = 0; t1 < logn; t1 ++) {
        bl[0][t1] = {0, 0};
    }
    //cout << "glaf\n";
    dfs(0, 0, 0, 0);
    //for (int t1 = 0; t1 < n; t1 ++) {
    //    for (int t2 = 0; t2 < logn; t2 ++) {
    //        cout << bl[t1][t2].second << " ";
    //    }
    //    cout << '\n';
    //}
    for (int t1 = 0; t1 < q; t1 ++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        int c = lca(a, b);
        //cout << "lca de " << a << " " << b << " " << c << '\n';
        //int da = dep[a] - dep[c];
        //int db = dep[b] - dep[c];
        //int res = max(sub(a, da), sub(b, db));
        cout << c << '\n';
    }
}

signed main() {
    //*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*/
    int t = 1;
    //cin >> t;
    for (int t1 = 0; t1 < t; t1 ++) {
        solve();
    }
    return 0;
}