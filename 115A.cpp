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
const int mxN = 20001;
int n;
vt<int> adj[mxN];
int vis[mxN];
int dfs(int v){
     vis[v]=1;
     int ans=1;
     for(auto u : adj[v]){
        ans = max(ans, 1+ dfs(u));
     }
     return ans;
}
void solve(){
   cin>>n;
   for(int i=1; i<=n; i++){
      int x; cin>>x;
      if(x==-1)continue;
      adj[x].pb(i);
   }
   int res=0;
   for(int i=1; i<=n; i++){
      if(!vis[i]){
         res = max(res, dfs(i));
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
   // read(t);
    while(t--){
        solve();
    }
    
}