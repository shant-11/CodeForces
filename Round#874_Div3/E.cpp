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

class UnionFind{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    public:

     int count;

    UnionFind(int n)
    {
       for(int i=1; i<=n; i++)
         parent[i]=i;

       count = n;
    }
    
    int find(int x)
    {
        if(parent[x] != x) 
         parent[x] = find(parent[x]);

        return parent[x];
    }

    void union_(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);

        if( xset == yset)
        return;

        count--;
        if(rank[xset] < rank[yset]) parent[xset] = yset;
        else if( rank[yset] < rank[xset]) parent[yset] = xset;
        else
        {
            parent[yset] = xset;
            rank[xset]++;
        }
    }

};

void solve(){
    int n;
    read(n);
    UnionFind uf(n);
    vt<int> a(n+1);
    for(int i=1; i<=n; i++)
    { cin>>a[i];}

    unordered_map<int, set<int>> pairs;
    for(int i=1; i<=n; i++)
    {
        uf.union_(i,a[i]);
        pairs[i].insert(a[i]);
        pairs[a[i]].insert(i);
    }

    unordered_map<int, set<int>> groups;
    F_OR(i,1,n+1,1)
    {
        int x = uf.find(i);
        groups[x].insert(i);
    }
    int inComplete = 0;
    EACH(x,groups)
    {
        EACH(y,x.second)
        {
            if(pairs[y].size()==1)
            {
                inComplete++;
                break;
            }
        }
    }
    int complete = uf.count - inComplete;
    if(complete == uf.count)
    {
        cout<<uf.count<<" "<<uf.count<<endl;
    }
    else
    {
        cout<<complete+1<<" "<<uf.count<<endl;
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