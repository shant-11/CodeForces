#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define EACH(x, a) for (auto& x:a)

template<class T> void read(T& x){
    cin>>x;
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x){
    EACH(a, x)
      read(a);
}
template<class A, size_t S> void read(ar<A, S>& x) {
	EACH(a, x)
		read(a);
}

const ll md=1000000007;
const int d4i[4]={-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

int n,m;
vt<vt<int>> a;
vt<vt<bool>> vis;

ll dfs(int i, int j){
    vis[i][j]=1;
    ll ans=a[i][j];
    for(int k=0; k<4; k++){
        int r = i + d4i[k];
        int c = j + d4j[k];
        if(r>=0 && r<n && c>=0 && c<m){
            if(!vis[r][c] && a[r][c] > 0)
            ans += dfs(r,c);
        } 
    }
    return ans;
}

void solve(){
    cin>>n>>m;
   a.clear(); vis.clear();
   a.resize(n,vt<int>(m));
   vis.resize(n,vt<bool>(m,false));

   for(int i=0; i<n; i++) read(a[i]);
   
   ll res = 0;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(!vis[i][j] && a[i][j] > 0){
          res = max(res, dfs(i,j) );
        }
    }
   }
   cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    read(t);
    while(t--){
        solve();
    }
    
}