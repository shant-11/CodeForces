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

vector<int> find(int& n){
    vt<int> res;
    if(n%2 == 0) res.pb(2);
    
    for(int i=3; i*i <= n; i+=2){
        if(n%i == 0){
            res.pb(i);
            if(res.size() == 2) return res;
        }
    }
    res.pb(n);
    return res;
}

void solve(){
   ll n,k;
   cin>>n>>k;
   vt<ll> a(n);
   ll sum =0;
   for(int i=0; i<n; i++){
    cin>>a[i];
    sum += a[i];
   }
   ll x = n*(n+1)/2 - sum;

   int pos = k % (n+1);
   if(pos == 0){
    for(auto & num : a) cout<<num<<" ";
    cout<<'\n';
    return;
   }
   vt<int> ans(n);
   ans[pos-1] = x;
   int i=0;
   int j = pos;
   while(j < n){
      ans[j] = a[i];
      j++;
      i++;
   }
   i++;
   j=0;
   while(i<n){
     ans[j] = a[i];
     j++;
     i++;
   }
   for(auto& num : ans) cout<<num<<" ";
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