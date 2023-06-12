#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back

#define all(x) x.begin(), x.end()
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
    int n; cin>>n; 
    vt<int> a(n), b(n-1),c(n-2); read(a); read(b); read(c);
    sort(all(a)); sort(all(b)); sort(all(c));
    int i=0;
    for( ; i<n-1; i++){
        if(a[i] != b[i]){
            cout<<a[i]<<'\n';
            break;
        }
    }
    if(i==n-1)cout<<a[n-1]<<'\n';
    i=0;
    for(; i<n-2; i++){
        if(b[i] != c[i]){
            cout<<b[i]<<'\n'; break;
        }
    }
    if(i==n-2)cout<<b[n-2]<<'\n';
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