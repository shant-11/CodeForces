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

bool check(vt<pair<int, int>>& p){
     vt<int> a,b;
     for(int i=0; i<p.size(); i++){
        a.pb(p[i].F);
        b.pb(p[i].S);
     }
     sort(all(a)); 
     sort(all(b));
     int count =1;
     for(int i=1; i<a.size(); i++){
        if(a[i] != a[i-1]){
            count=1;
            continue;
        }
        count++;
        if(count >= 3) return true;
     }
     count=1;
     for(int i=1; i<b.size(); i++){
        if(b[i] != b[i-1]){
            count=1;
            continue;
        }
        count++;
        if(count >= 3) return true;
     }
      int cnt1=0, cnt2=0;
     set<pair<int, int>> diag1={{0,0}, {1,1},{2,2}};
     set<pair<int, int>> diag2 = {{0,2},{1,1}, {2,0}};
     for(int i=0; i<p.size(); i++){
        if(diag1.find(p[i]) != diag1.end()) cnt1++;

        if(diag2.find(p[i]) != diag2.end()) cnt2++;
     }
     if( cnt1 ==3 || cnt2 ==3) return true;

     return false;
}

void solve(){
   vt<pair<int, int>> X,O,plus;
   char ch;
   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cin>>ch;
        if(ch == 'X'){
            X.pb({i,j});
            continue;
        }
        if( ch == '+'){
            plus.pb({i,j});
            continue;
        }
        if(ch== 'O'){
           O.pb({i,j});
        }
    }
   }
   if(X.size() >= 3 && check(X)){
    cout<<"X"<<'\n';
    return;
   }
   else if(O.size() >= 3 && check(O)){
    cout<<"O"<<'\n';
    return;
   }
   else if(plus.size() >= 3 && check(plus)){
    cout<<"+"<<'\n';
    return;
   }

   cout<<"DRAW"<<'\n';
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