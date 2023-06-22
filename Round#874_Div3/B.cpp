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
    int n,k;
    read(n); read(k);
    
    vt<int> b(n),res(n);
    pair<int, int> a[n];
    F_OR(i,0,n,1)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
    read(b);
    sort(a, a+n);
    sort(b.begin(),b.end());

    F_OR(i,0,n,1)
    {
        res[a[i].second]=b[i];
    }
    F_OR(i,0,n,1)
    cout<<res[i]<<" ";

   cout<<endl;

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