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

const int mxN=2e5;
void solve(){
    int n; read(n);
    string s; read(s);
    ll x=0;
    vt<int> v;
    
    for(int i=0; i<n; i++){
        if(s[i]=='L'){
            x += i;
            v.pb( (n-1-i) - i);
        }
        else{
            x += n-1-i;
            v.pb( i- (n-1-i));
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<n; i++){
        if(v[i]>0) x+=v[i];

        cout<<x<<" ";
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