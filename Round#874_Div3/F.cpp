#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
const long long md=1000000007;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define EACH(x, a) for (auto& x:a)

template<class T> void read(T& x){
      cin>>x;
}
template<class A> void read(vt<A>& x){
      EACH(a, x)
         read(a);
}
long long mult(long long a, long long b)
{
    long long res = 0;
    a= a%md;
    while(b)
    {
        if(b&1) res = (res%md + a%md)%md;
        a = (a*2)%md;
        b= b/2; 
    }

    return res%md;
}
void solve()
{
    int n,m;
    read(n); read(m);
    vt<int> a;
    int tmp;
    unordered_map<int,int> freq;
    F_OR(i,0,n,1)
    {
      cin>>tmp;
      if(freq[tmp]==0)
      a.pb(tmp);

      freq[tmp]++;  
    }
    sort(a.begin(), a.end());

    int s=0, e=0, l = a.size(),res =0;
    vt<int> currFreq;
    while(e< l)
    {
         currFreq.pb(freq[a[e]]);
        if( a[e]-a[s] >=m)
        {
            currFreq.erase(currFreq.begin());
            s++;
        }

        if(e-s+1 == m && a[e] - a[s] < m)
        {
           
           EACH(x,currFreq)
           res = res%mod + 
           s++;
        }
        e++; 
    }
    cout<<res<<endl;
    
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