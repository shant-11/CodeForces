#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

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
const int mxN = 2e5+1;

int dfs(vt<vt<int>> &adj, int v, vt<bool> &vis, vt<int>& res){
    
    vis[v] = true;
    bool f= 0;
    for(auto u : adj[v]){
        if(!vis[u]){
        res[v] += dfs(adj, u, vis, res);
        f = 1;
        }
    }
    if(!f) res[v] = 1;
    return res[v];
}
void solve(){
   int n;
   cin>>n;
   vt<vt<int>> adj(n+1);
   vt<bool> vis(n+1, false);
   vt<int> res(n+1,0);
   for(int i=1; i<n; i++){
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   dfs(adj, 1, vis, res);
   int q;
   cin>>q;
   vt<ll> ans;
   for(int i=0; i<q; i++){
      int x,y; cin>>x>>y;
      ll val = 1LL*res[x]*res[y];
      ans.pb(val);
   }
   for(auto x : ans)cout<<x<<'\n';

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