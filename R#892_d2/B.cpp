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
  int n;
  cin>>n;
  vt<int> a;
  vt<pair<int, int>> res;
  for(int i=0; i<n; i++){
     int m;
     cin>>m;
     int mn1 = INT_MAX , mn2 = INT_MAX;
     for(int j=0; j<m; j++){
        int x;
        cin>>x;
        if(x < mn1){
          mn2 = mn1;
          mn1 = x;
        }
        else if(x < mn2) mn2 = x;
     }  
     res.pb({mn1, mn2});   
  }
  if(n == 1){
    cout<<res[0].first<< '\n';
    return;
  }
  sort(all(res));
  ll ans = 0;
  ans += res[0].first;
  for(auto& p : res) a.pb(p.S);
  int mn = INT_MAX;
  for(auto& num : a){
   mn = min(mn, num);
   ans += num;
  }
  ans -= mn;
 cout<<ans<<'\n';
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