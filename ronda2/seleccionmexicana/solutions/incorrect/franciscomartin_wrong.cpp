#include <bits/stdc++.h>
using namespace std;
using ll = int;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

struct SCC{
    vector<vll> g, rg, nodes; vll order, comp;
    vector<bool> vis, rvis; ll n, c=0;
    SCC(ll N){
        n=N; g.assign(n,vll()); rg.assign(n,vll());
        nodes.assign(n,vll()); comp.assign(n,0);
        vis.assign(n,false); rvis.assign(n,false);
    }
    void Add(ll v,ll u){g[v].push_back(u); rg[u].push_back(v);}
    void dfs1(ll v){
        vis[v]=true;
        for(auto u:g[v]) if(!vis[u]) dfs1(u);
        order.push_back(v);
    }
    void dfs2(ll v,ll c){
        rvis[v]=true; comp[v]=c;
        for(auto u:rg[v]) if(!rvis[u]) dfs2(u,c);
    }
    void Solve(){
        for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);
        reverse(order.begin(),order.end()); 
        for(auto v:order) if(!rvis[v]) dfs2(v,c), c++;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    ll n, m, t, a, b;
    cin >> n >> m;
    vector<array<ll,3>> A(m); SCC scc(2*n);
    for(int i=0; i<m; i++){
        cin >> t >> a >> b; a--; b--; a=2*a; b=2*b;
        if(t==1) scc.Add(a,b), scc.Add(b^1,a^1);
        else if(t==2) scc.Add(a,b^1), scc.Add(b,a^1);
        else if(t==3) scc.Add(a^1,b), scc.Add(b^1,a);
    }
    vll comp=scc.comp;
    for(int i=0; i<2*n; i+=2) if(comp[i]==comp[i+1]){cout << "NO\n"; return 0;}
    cout << "SI\n";
}