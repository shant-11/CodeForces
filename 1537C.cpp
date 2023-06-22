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
    vt<int> h(n); read(h);
    sort(all(h));

    if(n<3){
        EACH(x , h) cout<<x<<" ";
        cout<<'\n';
        return ;
    }
    int mn = INT_MAX, pos;
    for(int i=1; i<n; i++){
        if(h[i]-h[i-1] < mn){
            mn = h[i]-h[i-1];
            pos=i;
        }
    }
    for(int i= pos; i<n; i++){
        cout<<h[i]<<" ";
    }
    for(int i=0; i<pos; i++)cout<<h[i]<<" ";

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