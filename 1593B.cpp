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

const string ending[] = { "00", "25", "50", "75" };

int solve(string& s, string& t){
    int r = s.size()-1;
    int ans=0;
    while(r >=0 && s[r] != t[1]){
        r--; ans++;
    }
    if(r < 0) return INT_MAX;
    
    r--;
    while(r>=0 && s[r] != t[0]){
        r--; 
        ans++;
    }
    return ( r < 0 ? INT_MAX : ans);
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
        string n; cin>>n;

        int res=INT_MAX;
        for(auto e : ending){
          res = min(res, solve(n, e));
        }
        cout<<res<<'\n';
    }
    
}