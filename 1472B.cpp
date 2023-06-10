#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool solve(long long *arr, int n)
    {
        int count_1 =0;
        int count_2 =0;

        for(int i=0; i<n; i++)
        {
            if(arr[i]==1)
            count_1++;
            else
            count_2++;
        }

     if(count_1 %2 != 0)
     return false;

     else if(count_2 % 2 == 0 && count_1 % 2 == 0)
     return true;
     
     else
     {
        if(count_1<2)
        return false;
        else
        return true;
     }

    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;
        
        if(n > 0)
        {
        long long arr[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;

        bool res = ob.solve(arr,n);

        if(res)
        cout << "YES"<<endl;
        else
        cout << "NO"<<endl;
        }
        
        
    }
    return 0;
}