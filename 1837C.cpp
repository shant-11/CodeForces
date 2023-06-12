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
  string s; cin>>s;
  int n= s.size();
  s = "0" + s + "1";
  int i=1;
  while(i<=n){
     if(s[i]=='?'){
        int l=i,r=i;
        while(l >=0 && s[l]=='?')l--;
        while(r <=n+1 && s[r]=='?')r++;
        if(s[l]=='1' && s[r]=='1'){
            while(i<r){
                s[i]='1';
                i++;
            }
        }
        else{
             while(i<r){
                s[i]='0';
                i++;
            }
        }
     }
     i++;
  }
  s.pop_back();
  s.erase(s.begin());
  cout<<s<<'\n';
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