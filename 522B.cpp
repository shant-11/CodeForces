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
   int n; cin>>n;
   int w[n], h[n];
   pair<int, int> mxH = {0,-1};
   ll wSum=0;
   for(int i=0; i<n; i++){
     cin>>w[i]>>h[i];
     wSum += w[i];
     if(h[i] > mxH.first){
        mxH.first = h[i];
        mxH.second = i;
     }
   } 
   int mxH2 = 0;
   for(int i=0; i<n; i++){
      if(i==mxH.second) continue;

      if(h[i] > mxH2){
        mxH2 = h[i];
      }
   }

   for(int i=0; i<n; i++){
     if(i == mxH.second){
        cout<<( (wSum - w[i])*mxH2)<<" ";  
     }
     else{
        cout<<( (wSum - w[i])*(mxH.first))<<" ";
     }
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
   // read(t);
    while(t--){
        solve();
    }
    
}