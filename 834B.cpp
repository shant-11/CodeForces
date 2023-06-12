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
    int n; int k;
    cin>>n>>k;
    string s; cin>>s;
    pair<int, int> ch[26];
    vt<bool> vis(26, 0);
    unordered_map<char, bool> mp;
    int i=0;
    while(i <n){
        if(!vis[s[i]-'A']){
          ch[s[i]-'A'].F = i;
          vis[s[i]-'A']= 1;
        }
        i++;
    }
    i = n-1;
    vis.assign(26,0);
    while(i >=0){
        if(!vis[s[i]-'A']){
          ch[s[i]-'A'].S = i;
          vis[s[i]-'A']= 1;
        }
        i--;
    }
    i = 0;
    for(; i<n; i++){
        mp[s[i]-'A']=1;
        if(mp.size() > k){
            cout<<"YES";
            break;
        }
        if(ch[s[i]-'A'].S ==i){
            mp.erase(s[i]-'A');
        }
        
    }
    if(i==n)cout<<"NO";
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