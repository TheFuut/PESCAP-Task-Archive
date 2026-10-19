#include <bits/stdc++.h>
#define fore(v,l,r) for(int v = l; v < (r); v++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
constexpr ll MOD = 1e9+7;
constexpr int INF = 1e9;

void solve2(int N) {
    vector<vi> a(N, vi(N)), vis(N, vi(N,0));
    fore(i,0,N) fore(j,0,N) cin >> a[i][j];
    int left = N*N;

    ll s_a = 0, s_b = 0;
    bool alt = true;

    while(left>0) {
        ll ms = 0, mi=0, mj=0;
        fore(i,0,N) fore(j,0,N) {
            if(vis[i][j]) continue;
            ll s = a[i][j];
            if(i+1<N && !vis[i+1][j]) s += a[i+1][j];
            if(i-1>=0 && !vis[i-1][j]) s += a[i-1][j];
            if(j+1<N && !vis[i][j+1]) s += a[i][j+1];
            if(j-1>=0 && !vis[i][j-1]) s += a[i][j-1];

            if(s > ms) {
                ms = s;
                mi = i; mj = j;
            }
        }

        vis[mi][mj] = 1; left--;
        if(mi+1<N && !vis[mi+1][mj]) {vis[mi+1][mj]=1; left--;}
        if(mi-1>=0 && !vis[mi-1][mj]) {vis[mi-1][mj]=1; left--;}
        if(mj+1<N && !vis[mi][mj+1]) {vis[mi][mj+1]=1; left--;}
        if(mj-1>=0 && !vis[mi][mj-1]) {vis[mi][mj-1]=1; left--;}
        if(alt) s_a += ms;
        else s_b += ms;
        alt = !alt;
    }
    cout << s_a << ' ' << s_b << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N; 

    if(N<=50) {solve2(N);return 0;}
    
    vector<vi> a(N, vi(N));
    fore(i,0,N) fore(j,0,N) cin >> a[i][j];
    priority_queue<pair<ll,pii>> f;
    fore(i,0,N) fore(j,0,N) {
        ll s = a[i][j];
        if(i+1<N) s += a[i+1][j];
        if(i-1>=0) s += a[i-1][j];
        if(j+1<N) s += a[i][j+1];
        if(j-1>=0) s += a[i][j-1];
        f.push({s, {i,j}});
    }

    ll s_a = 0, s_b = 0;
    vector<vi> vis(N,vi(N,0));
    bool alt = true;
    while(!f.empty()) {
        auto[S, p] = f.top(); f.pop();
        auto[i,j] = p;

        if(vis[i][j]) continue;

        ll s = a[i][j];
        if(i+1<N && !vis[i+1][j]) s += a[i+1][j];
        if(i-1>=0 && !vis[i-1][j]) s += a[i-1][j];
        if(j+1<N && !vis[i][j+1]) s += a[i][j+1];
        if(j-1>=0 && !vis[i][j-1]) s += a[i][j-1];
        if(S != s) {
            f.push({s, {i,j}});
            continue;
        } else {
            // cout << i << ' ' << j << '\n';
            if(alt) s_a += S;
            else s_b += S;
            alt = !alt;
            a[i][j] = 0;
            vis[i][j] = 1;
            if(i+1<N) vis[i+1][j] = 1; //a[i+1][j] = 0;}
            if(i-1>=0) vis[i-1][j] = 1; //a[i-1][j] = 0;}
            if(j+1<N) vis[i][j+1] = 1; //a[i][j+1] = 0;}
            if(j-1>=0) vis[i][j-1] = 1; //a[i][j-1] = 0;}
            // cout << s_a << ' ' << s_b << '\n';
        }
    }
    cout << s_a << ' ' << s_b << '\n';
    return 0;
}