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

struct {
    bool operator()(vt<int>&v1, vt<int>& v2){
    if(v1[0] != v2[0]){
        return v1[0] > v2[0];
    }
    if(v1[1] != v2[1]){
        return v1[1] < v2[1];
    }
    return v1[2] < v2[2];
    }
}abc;
void solve(){
   int n, m,h;
   cin>>n>>m>>h;
   vt<vt<int>> data(n,vt<int>(m));
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
         cin>>data[i][j];
    }
   }
   vt<vt<int>> triplets(n, vt<int>(3));

   for(int i=0; i<n; i++){
    sort(all(data[i]));
    int count=0;
    int sum=0;
    vt<int> pen;
    for(int j=0; j<m; j++){
       sum += data[i][j];
       if(sum > h) break;
       
       count++;
       pen.pb(sum);
    }
    triplets[i][0]=count;
    triplets[i][1]= accumulate(all(pen), 0);
    triplets[i][2]=i;
    
   }
   sort(all(triplets), abc);
   int ans=1;
   for(int i=0; i<n; i++){
      if(triplets[i][2] == 0)
      break;

      ans++;
   }

   cout<<ans<<'\n';
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