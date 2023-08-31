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


void solve(){
   int n,m;
   cin>>n>>m;
   vt<vt<char>> grid(n,vt<char>(m, '.')), ans(n,vt<char>(m,'.'));
   bool f = false;
   for(int i=0; i<n; i++){
    int cnt =0;
    vt<char> U = {'W', 'B'};
    vt<char> D = {'B', 'W'};
    bool f1 = false;
    bool f2 = false;
    for(int j=0; j<m; j++){
        cin>>grid[i][j];
        if(grid[i][j] != '.') cnt++;

        if(grid[i][j] == 'U'){
            ans[i][j] = U[f1];
            f1 = !f1;
        }
        if(grid[i][j] == 'D'){
            ans[i][j] = D[f2];
            f2 = !f2;
        }
    }
    if(cnt%2 != 0) f = true;
   }
   if(f){
    cout<<-1<<'\n';
    return;
   }

   for(int j=0; j<m; j++){
    int cnt=0;
    vt<char> L = {'W', 'B'};
    vt<char> R = {'B', 'W'};
    bool f1 = false;
    bool f2 = false;
    for(int i=0; i<n; i++){
      if(grid[i][j] != '.') cnt++;
      if(grid[i][j] == 'L'){
         ans[i][j] = L[f1];
         f1 = !f1;
      }
      if(grid[i][j] == 'R'){
        ans[i][j] = R[f2];
        f2 = !f2;
      }
    }
    if(cnt%2 != 0) {
        cout<<-1<<'\n';
        return;
    }
   }

   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout<<ans[i][j];
    }
    cout<<'\n';
   }
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