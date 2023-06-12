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

void solve(){
    int n,m; cin>>n;
    vt<int> b(n); read(b);
    cin>>m; 
    vt<int> g(m); read(g);
    sort(b.begin(), b.end()); sort(g.begin(), g.end());
    int p1=0, p2=0;
    int res=0;
    while(p1<n && p2<m){
        if(abs(b[p1]-g[p2]) > 1 ){
            (b[p1] < g[p2]) ? p1++ : p2++;
            continue; 
        }
        res++;
        p1++; p2++;
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
    //read(t);
    while(t--){
        solve();
    }
    
}