
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
const ll mxN = 2e9;

void solve(){
   ll n;
   cin>>n;
   ll l=2, r = mxN;
   ll ans = -1;
   while(l<=r){
     ll m = l + (r-l)/2;
     if(m*m - m - 2*n == 0){
        cout<<m<<'\n';
        return;
     }
     else if(m*m - m - 2*n < 0){
        ans = m;
        l = m+1;
     }
     else r = m-1;
   }
   ll t = ans*ans - ans - 2*n;
   t = t/2;
   t = abs(t);
   cout<<ans + t<<'\n';
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