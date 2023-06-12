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
    int n,q; cin>>n>>q;
    int a[n]; ll presum[n+1];
    presum[0]=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        presum[i+1] = a[i] + presum[i];
    }
    ll sum = presum[n];
    for(int i=0; i<q; i++){
        int l,r,k; read(l,r,k);
        sum = presum[n] - (presum[r]-presum[l-1]) + 1LL*k *(r -l +1); 
        if(sum&1)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
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