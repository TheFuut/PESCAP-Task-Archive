#include <bits/stdc++.h>

using namespace std;


struct segtree {
    struct nodo {
        int val = 0;
    };
    int n, k;
    vector<nodo> seg;
    segtree(int N, int K) {
        n = N;
        k = K;
        seg.resize(4*n);
    }
    void act(int v, int l, int r, int p) {
        if (p < l || r < p) return ;
        if (l == r) {
            seg[v].val ++;
            return ;
        }
        int mit = (l + r) >> 1;
        act(v<<1,l,mit,p);
        act(v<<1|1,mit+1,r,p);
        seg[v].val = seg[v<<1].val + seg[v<<1|1].val;
        return ;
    }
    void act(int pos) {
        if (pos + k - 1 >= n) return ;
        act(1, 0, n-1,pos);
        if (pos+k>=n) return ;
        act(1, 0, n-1, pos+k);
        return ;
    }
    int sum(int v, int l, int r, int p) {
        if (r < p) return seg[v].val;
        if (p < l) return 0;
        if (l == r) return seg[v].val;
        int mit = (l + r) >> 1;
        return sum(v<<1,l,mit,p) + sum(v<<1|1,mit+1,r,p);
    }
    int sum(int pos) {
        return sum(1,0,n-1,pos);
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    segtree sg1(n, k);
    segtree sg2(n, k);
    vector<int> ini(n), to(n);
    for (int t1 = 0; t1 < n; t1 ++) {
        cin >> ini[t1];
        ini[t1] --;
    }
    for (int t1 = 0; t1 < n; t1 ++) {
        cin >> to[t1];
        to[t1] --;
    }
    int act = 0;
    for (int t1 = 0; t1 < n - k + 1; t1 ++) {
        if (sg1.sum(t1)&1) {
            ini[t1] ^= 1;
        }
        if (sg2.sum(t1)&1) {
            ini[t1] ^= 2;
        }
        if ((ini[t1]^to[t1])&1){
            sg1.act(t1);
            act ++;
        }
        if ((ini[t1]^to[t1])&2){
            sg2.act(t1);
            act ++;
        }
    }
    for (int t1 = n - k +1; t1 < n; t1 ++) {
        if (sg1.sum(t1)&1) {
            ini[t1] ^= 1;
        }
        if (sg2.sum(t1)&1) {
            ini[t1] ^= 2;
        }
        if (ini[t1] != to[t1]) {
            cout << -1 << '\n';
            return ;
        }
    }
    cout << act << '\n';
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