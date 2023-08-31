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

struct {
   bool operator()(pair<int, int>&a, pair<int, int>&b){
      if(a.first == b.F) return a.S < b.S;

      return a.F > b.F;
   }
}comp;

void solve(){
  int n, k,x;
  cin>>n>>k;
  vt<pair<int, int>> v;
  vt<int> ans;
  for(int i=1; i<=n; i++){
      cin>>x;
      if(x%k == 0)cout<<i<<" ";
      else
      v.pb({x%k, i});
  }
  sort(all(v), comp);
  for(auto& p : v){
    cout<<p.second<<" ";
  }
  
  cout<<'\n';
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