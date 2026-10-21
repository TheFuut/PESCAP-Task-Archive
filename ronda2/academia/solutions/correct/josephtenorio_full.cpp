#include <bits/stdc++.h>

using namespace std;

struct nodo {
    int lis = 0;
    nodo *iz;
    nodo *de;
    nodo() {
        lis = 0;
        iz = nullptr;
        de = nullptr;
    }
};

int que(nodo *v, int l, int r, int lq, int rq){ 
    if (rq < lq) return 0;
    if (r < lq || rq < l) return 0;
    if (lq <= l && r <= rq) return v->lis;
    int mit = (l + r) >> 1;
    int iz = 0, de = 0;
    if (v->iz) iz = que(v->iz,l,mit,lq,rq);
    if (v->de) de = que(v->de,mit+1,r,lq,rq);
    return max(iz, de);
}

void upd(nodo *v, int l, int r, int p, int va) {
    if (l == r) {
        v->lis = va;
        return;
    }
    int mit = (l + r) >> 1;
    if (p <= mit) {
        if (v->iz == nullptr) v->iz = new nodo();
        upd(v->iz, l, mit, p, va);
    } else {
        if (v->de == nullptr) v->de = new nodo();
        upd(v->de, mit + 1, r, p, va);
    }
    int iz = (v->iz ? v->iz->lis : 0);
    int de = (v->de ? v->de->lis : 0);
    v->lis = max(iz, de);
    return ;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ns(n);
    int mx = 0;
    for (int t1 = 0; t1 < n; t1 ++) {
        cin >> ns[t1].first  >> ns[t1].second;
        mx = max(mx, ns[t1].second);
    }
    nodo *seg = new nodo();
    sort(ns.begin(), ns.end());
    int l = 0;
    for (; l < n;) {
        stack<pair<int, int>> act;
        int toca = ns[l].first;
        while (ns[l].first == toca) {
            act.push({ns[l].second, que(seg,0,mx,0,ns[l].second-1)+1});
            l ++;
        }
        while (!act.empty()) {
            upd(seg,0,mx,act.top().first, act.top().second);
            act.pop();
        }
    }
    cout << que(seg,0,mx,0,mx) << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int tt = 0; tt < t; tt ++) {
        solve();
    }
    return 0;
}