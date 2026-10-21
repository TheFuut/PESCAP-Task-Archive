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
    if (v->iz == nullptr) v->iz = new nodo();
    if (v->de == nullptr) v->de = new nodo();
    return max(que(v->iz,l,mit,lq,rq), que(v->de,mit+1,r,lq,rq));
}

void upd(nodo *v, int l, int r, int p, int va) {
    if (r < p || p < l) return ;
    if (l == r) {
        v->lis = va;
        return  ;
    }
    int mit = (l + r) >> 1;
    if (v->iz == nullptr) v->iz = new nodo();
    if (v->de == nullptr) v->de = new nodo();
    upd(v->iz,l,mit,p,va);
    upd(v->de,mit+1,r,p,va);
    v->lis = max(v->iz->lis, v->de->lis);
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