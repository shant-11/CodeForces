#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define EACH(x, a) for (auto& x:a)

template<class T> void read(T& x){
      cin>>x;
}
template<class A> void read(vt<A>& x){
      EACH(a, x)
         read(a);
}
void solve()
{
    int n;
    read(n);
    string s;
    read(s);
    unordered_map<string, int> mp;
    string t = to_string(s[0]) + to_string(s[1]);
    int count=1;
    mp[t]++;
    F_OR(i,2,n,1)
    {
       t= to_string(s[i-1])+ to_string(s[i]);
       if(mp.find(t) != mp.end() )
       {
        continue;
       }
       else
       {
        mp[t]++;
        count++;
       }
    }
    cout<<count<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    read(t);
    while(t--)
   {
        solve();
    } 
    return 0;
}