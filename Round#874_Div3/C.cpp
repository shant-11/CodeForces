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
    vt<int> a(n);
    read(a);
    int  odd=-1;
    EACH(x,a)
    {
        if(x%2 != 0)
        {
            if(odd == -1)
            odd = x;
           
           odd = min(odd,x);
        }
    }

    if(odd == -1)
    {
    cout<<"YES"<<endl;
    return;
    }

    bool iseven=true, isodd=true;
     EACH(y,a)
     {
        if(y%2 != 0)
        {
           if(y-odd <= 0)
           {
            iseven = false;
             break;
           }
        }
    }

    EACH(y,a)
     {
        if(y%2 == 0)
        {
           if(y-odd <= 0)
           {
            isodd = false;
             break;
           }
        }
    }

   if(iseven || isodd)
   {cout<<"YES"<<endl;}
   else
   {
    cout<<"NO"<<endl;
   }

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