// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long

// #define ar array
// #define vt vector
// #define pb push_back

// #define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
// #define EACH(x, a) for (auto& x:a)

// template<class T> void read(T& x){
//     cin>>x;
// }
// template<class H, class... T> void read(H& h, T&... t) {
// 	read(h);
// 	read(t...);
// }
// template<class A> void read(vt<A>& x){
//     EACH(a, x)
//       read(a);
// }
// template<class A, size_t S> void read(ar<A, S>& x) {
// 	EACH(a, x)
// 		read(a);
// }

// const ll md=1000000007;
// const int d4i[4]={-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

// void solve(){
//    // queue<int> q;
//     string s1, s2;
//    int t,qy;
//    vector<int> mp;
    
//    cin>>s1>>s2;
//    cin>>t>>qy;
//    int n= s1.size();
//    for(int i=0; i<qy; i++){
//     int num;
//     cin>>num;
//       if(num==1){
//         int a; cin>>a;
//         if(mp.size()==t){
//             mp.erase(mp.begin());
//         }
//         mp.pb(a);
//        // mp[a]=true;
//       }
//       else if(num==2){
//          int x,px, y,py;
//          read(x,px,y,py);
//          if(x==1 && y==1)swap(s1[px-1],s1[py-1]);
//          else if(x==2 && y==2)swap(s2[px-1], s2[py-1]);
//          else if(x==1 && y==2){
//             char tmp= s1[px-1];
//             s1[px-1]=s2[py-1];
//             s2[py-1]=tmp;
//          }
//          else{
//             char tmp= s2[px-1];
//             s2[px-1]=s1[py-1];
//             s1[py-1]=tmp;
//          }
//          if(mp.size()==t){
//             // if(q.front() != -1)
//             // mp.erase(q.front());

//             mp.erase(mp.begin());
//         }
//         mp.pb(-1);

//       }
//       else{
//            if(mp.size()==t){
//             // if(q.front() != -1)
//             // mp.erase(q.front());

//             mp.erase(mp.begin());
//         }
//         mp.pb(-1);
//         //int flag=false;
//         string st1=s1, st2=s2;
//         vector<int> tv;
//         tv=mp;
//         sort(tv.begin(), tv.end());
//         int c=0;
//         for(auto p : tv){
//             if(p == -1)
//             continue;
//             st1.erase(p-1-c,1);
//             st2.erase(p-1-c,1);
//             c++;
//         }
//         // for(int i=0; i<n; i++){
//         //     if(mp[i+1]==false && s1[i]!=s2[i]){
//         //         cout<<"NO"<<'\n'; 
//         //         flag = true; break;
//         //     }   
//         // }
//         if(st1==st2)cout<<"YES"<<'\n';
//         else cout<<"NO"<<'\n';
//       }
//    }
// }


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
    
//     int t=1;
//     read(t);
//     while(t--){
//         solve();
//     }
    
// }
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back

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
    queue<int> q;
    string s1, s2;
    int t,qy;
    unordered_map<int, bool> mp;
   cin>>s1>>s2;
   cin>>t>>qy;
   int n= s1.size();
   for(int i=0; i<qy; i++){
    int num;
    cin>>num;
      if(num==1){
        int a; cin>>a;
        if(q.size()==t){
            if(q.front() != -1)
            mp.erase(q.front());

            q.pop();
        }
        q.push(a);
        mp[a]=true;
      }
      else if(num==2){
         int x,px, y,py;
         read(x,px,y,py);
         if(x==1 && y==1)swap(s1[px-1],s1[py-1]);
         else if(x==2 && y==2)swap(s2[px-1], s2[py-1]);
         else if(x==1 && y==2){
            char tmp= s1[px-1];
            s1[px-1]=s2[py-1];
            s2[py-1]=tmp;
         }
         else{
            char tmp= s2[px-1];
            s2[px-1]=s1[py-1];
            s1[py-1]=tmp;
         }
         if(q.size()==t){
            if(q.front() != -1)
            mp.erase(q.front());

            q.pop();
        }
        q.push(-1);

      }
      else{
           if(q.size()==t){
            if(q.front() != -1)
            mp.erase(q.front());

            q.pop();
        }
        q.push(-1);
        int flag=false;
        for(int i=0; i<n; i++){
            if(mp[i+1]==false && s1[i]!=s2[i]){
                cout<<"NO"<<'\n'; 
                flag = true; break;
            }   
        }
        if(!flag)cout<<"YES"<<'\n';
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
    read(t);
    while(t--){
        solve();
    }
    
}