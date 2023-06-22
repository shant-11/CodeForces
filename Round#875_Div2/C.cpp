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
const int mxN = 2e5;
int dp[mxN+1], id[mxN+1];
vt<pair<int,int>> edg[mxN+1];

void dfs(int u){
    for(auto p : edg[u]){
        if(dp[p.first] == 0){
            dp[p.first] = dp[u] + ( p.second < id[u] );
            id[p.first] = p.second;
            dfs(p.first);
        }
    }
}

void solve(){
    int n;
    read(n);
    for(int i=1; i<=n; i++){
        dp[i]=0;
        id[i]=0;
        edg[i].clear();
    }
    F_OR(i,1,n,1){
        int u,v;
        read(u,v);
        edg[u].pb({v,i});
        edg[v].pb({u,i});
    }
    dp[1]=1;
    dfs(1);
    int res =0;
    for(int i=1; i<=n; i++){
        res = max(res,dp[i]);
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