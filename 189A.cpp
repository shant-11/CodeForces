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

int dp[40001];
bool vis[40001];
int dfs(int rem, int &a, int &b, int &c){
    if(rem == 0) return 0; 
    if(rem < 0) return -1;

    if(vis[rem]) return dp[rem];

   dp[rem] = max( dfs(rem-a, a, b, c),
                 max(dfs(rem-b, a, b, c),
                     dfs(rem-c, a, b, c)) );

   if(dp[rem] != -1)dp[rem]++;
   vis[rem] = 1;
   return dp[rem];
    
}
void solve(){
    int n,a,b,c;
    read(n,a,b,c);
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    
    dfs(n, a, b, c);
    cout<<dp[n];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    //read(t);
    while(t--){
        solve();
    }
    
}