#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;

struct casilla{
    int v1,v2,v3,v4;
    ll sum;
};

struct NODE{
    ll sum;
    int idx;
};

NODE combine(NODE A, NODE B){
    if(A.sum>=B.sum){
        return A;
    }
    return B;
}

struct Segtree{
  vector<NODE>tree;
  
  Segtree(int n){
      tree.assign(4*n,{});
  }
  
  
  void build(int node, int l, int r, vector<casilla>&conecciones){
      if(l==r){
          tree[node]={conecciones[l].sum,l};
          return;
      }
      int mid=(l+r)/2;
      build(2*node,l,mid,conecciones);
      build(2*node+1,mid+1,r,conecciones);
      tree[node]=combine(tree[2*node],tree[2*node+1]);
  }
  
  
  void update(int node, int l, int r, int pos, ll x){
      if(l==r){
          tree[node]={x,l};
          return;
      }
      int mid=(l+r)/2;
      
      if(pos<=mid){
          update(2*node,l,mid,pos,x);
      }else{
          update(2*node+1,mid+1,r,pos,x);
      }
      
      tree[node]=combine(tree[2*node],tree[2*node+1]);
      
  }
  
  // es lo mismo que query pero me da hueva escribirla solo casilla en el 1 y ya
  NODE query(){
      return tree[1];
  }
    
};

void solve(){
    int n;
    cin>>n;
    
    vector<vector<ll>>a(n+1,vector<ll>(n+1,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    
    vector<casilla>conecciones(n*n+5);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            int idx=i*n+j;
            
            if(i>=1){
                conecciones[idx].v1=(i-1)*n+j;
            }else{
                conecciones[idx].v1=-1;
            }
            //
            if(j>=1){
                conecciones[idx].v2=i*n+(j-1);
            }else{
                conecciones[idx].v2=-1;
            }
            //
            if(i<n-1){
                conecciones[idx].v3=(i+1)*n+j;
            }else{
                conecciones[idx].v3=-1;
            }
            //
            if(j<n-1){
                conecciones[idx].v4=i*n+(j+1);
            }else{
                conecciones[idx].v4=-1;
            }
            
            ///
            conecciones[idx].sum=a[i][j];
            if(conecciones[idx].v1!=-1)conecciones[idx].sum+=a[(i-1)][j];
            if(conecciones[idx].v2!=-1)conecciones[idx].sum+=a[i][(j-1)];
            if(conecciones[idx].v3!=-1)conecciones[idx].sum+=a[(i+1)][j];
            if(conecciones[idx].v4!=-1)conecciones[idx].sum+=a[i][(j+1)];
        }
    }
    
    Segtree st(n*n);
    st.build(1,0,n*n-1,conecciones);
    
    ll ans1=0;
    ll ans2=0;
    
    bool alberto=true;
    ll casillasvivas=n*n;
    vector<bool>visited(n*n+5,false);
    
    int sz=n*n;
    
    while(true){
        
        NODE maximo=st.query();
        //Casillas originales 
        
        if(maximo.sum<0)break;
        
        if(alberto){
            ans1+=maximo.sum;
            alberto=false;
        }else{
            ans2+=maximo.sum;
            alberto=true;
        }
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        visited[maximo.idx]=true;
        st.update(1,0,n*n-1,maximo.idx,-1e18);
        
        //bloquear conecciones
        if(conecciones[maximo.idx].v1!=-1){
            visited[conecciones[maximo.idx].v1]=true;
            st.update(1,0,n*n-1,conecciones[maximo.idx].v1,-1e18);
        }
        if(conecciones[maximo.idx].v2!=-1){
            visited[conecciones[maximo.idx].v2]=true;
            st.update(1,0,n*n-1,conecciones[maximo.idx].v2,-1e18);
        }
        if(conecciones[maximo.idx].v3!=-1){
            visited[conecciones[maximo.idx].v3]=true;
            st.update(1,0,n*n-1,conecciones[maximo.idx].v3,-1e18);
        }
        if(conecciones[maximo.idx].v4!=-1){
            visited[conecciones[maximo.idx].v4]=true;
            st.update(1,0,n*n-1,conecciones[maximo.idx].v4,-1e18);
        }
        
        vector<int> bloqueadas;
        bloqueadas.push_back(maximo.idx);
        bloqueadas.push_back(conecciones[maximo.idx].v1);
        bloqueadas.push_back(conecciones[maximo.idx].v2);
        bloqueadas.push_back(conecciones[maximo.idx].v3);
        bloqueadas.push_back(conecciones[maximo.idx].v4);
        
        
        //todos las bloqueadas para checar el calculo nuevo
        for(int i=0; i<5; i++){
            if(bloqueadas[i]==-1)continue;
            
            vector<int>vecinos;
            vecinos.push_back(conecciones[bloqueadas[i]].v1);
            vecinos.push_back(conecciones[bloqueadas[i]].v2);
            vecinos.push_back(conecciones[bloqueadas[i]].v3);
            vecinos.push_back(conecciones[bloqueadas[i]].v4);
            
            //ver los 4 vecinos posibles
            for(int j=0; j<4; j++){
                if(vecinos[j]==-1 || visited[vecinos[j]])continue;
                
                int I=vecinos[j]/n;
                int J=vecinos[j]%n;
                
                ll res=a[I][J];
                
                if(conecciones[vecinos[j]].v1!=-1 && !visited[conecciones[vecinos[j]].v1]){
                    res+=a[conecciones[vecinos[j]].v1/n][conecciones[vecinos[j]].v1%n];
                }
                if(conecciones[vecinos[j]].v2!=-1 && !visited[conecciones[vecinos[j]].v2]){
                    res+=a[conecciones[vecinos[j]].v2/n][conecciones[vecinos[j]].v2%n];
                }
                if(conecciones[vecinos[j]].v3!=-1 && !visited[conecciones[vecinos[j]].v3]){
                    res+=a[conecciones[vecinos[j]].v3/n][conecciones[vecinos[j]].v3%n];
                }
                if(conecciones[vecinos[j]].v4!=-1 && !visited[conecciones[vecinos[j]].v4]){
                    res+=a[conecciones[vecinos[j]].v4/n][conecciones[vecinos[j]].v4%n];
                }
                
                conecciones[vecinos[j]].sum=res;
                st.update(1,0,n*n-1,vecinos[j],res);
                
                
            }
            
        }
        
    }
    
    cout<<ans1<<" "<<ans2<<'\n';
    
    
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int t=1;
    
    while(t--)solve();
    
    return 0;
}