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
int fact[100];

ll expo(ll a, ll b, ll d){
    ll res = 1;
    while(b){
        if(b&1) res = ((res % d)*(a % d)) % d;
        a = ((a % d)*( a % d)) % d;
        b>>=1;
    }
    return res;
}
ll C(ll n, ll r){
    if(n < r) return 0;

    ll res= fact[n];

    res = ( res * expo(fact[r], md-2, md) ) % md;
    res = ( res * expo(fact[n-r], md-2, md)) % md;

    return res;

}
void solve(){
 ll k,l,r; read(k,l,r);
// vector<ll> v(r-l+1);
 ll res =0;
 for(ll i=l ; i<=r; i++){
    if(i&1){
        ll tmp1 = ( (expo(2,i/2, md) % md)+ (expo(2, i/2 + 1, md) % md ) -1) % md;
        res = (res + C(tmp1, k)) % md;
    }
    else{
        ll tmp2 = ( ( ( (expo(2, i/2, md) % md) * 2) % md) -1) % md;
        res = ( res + C(tmp2, k) ) % md;
    }
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
    fact[0]=1;
    for(ll i=1; i<md; i++){
        fact[i]= ( i * fact[i-1]) % md;
    }
    
    int t=1;
    //read(t);
    while(t--){
        solve();
    }
    
}