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
const int mxN=1e5;
int a[mxN];
void solve(){
   int n; read(n);
   vt<int> v;
   for(int i=0; i<n; i++){
    read(a[i]);
   }
   if(a[n-1]==1)cout<<"NO"<<'\n';
   else{
    cout<<"YES"<<'\n';
    int s=0; 
     for(int i=0; i<n; i++){
        if(a[i]==0){
            v.pb(i-s+1);
            s= i+1;
        }
      }
        for(auto rit=v.rbegin(); rit!=v.rend(); rit++){
            int l = *rit;
            for(int i=1; i<l; i++)
            cout<<0<<" ";

            cout<<l-1<<" ";
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