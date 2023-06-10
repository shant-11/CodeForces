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
const int mxN = 1e5;
ll p[mxN];
void solve(){
   ll n,d; read(n,d);
   ll res=0;
   F_OR(i,0,n,1){
     cin>>p[i];
   }
   sort(p,p+n);
   int l=0, r=n-1;
   while(l<=r){
       int x= d/p[r] + 1;
       l+= x-1;

       if(l<=r)
       res++;

       r--;
      }
   cout<<res;
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