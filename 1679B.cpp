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
  ll n,q; read(n,q);
  vt<ll> a(n); read(a);
  ll last_2q = 0, last_2q_val = 0;
  vt<ll> last_1q(n,0), last_1q_val(all(a));
  
  ll sum=0;
  EACH(x,a){sum += x;}

  for(ll i=1; i<=q; i++){
    ll type; cin>>type;
    if(type==1){
        ll index; ll x, tmp; read(index, x); index--;
        if(last_2q > last_1q[index]) tmp= last_2q_val;
        else tmp= last_1q_val[index];

        sum = sum - tmp + x;
        last_1q[index] = i; 
        last_1q_val[index] = x;   
    }
    else{
        ll x; cin>>x;
        last_2q = i; last_2q_val =x;
        sum = n * last_2q_val; 
    }
    cout<<sum<<'\n';
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
    //read(t);
    while(t--){
        solve();
    }
    
}