#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
    
    
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        string s;
        cin>>s;
 
        ll p=0;
        for(ll i=0;i<s.size();i++){
         if(s[i]!=s[s.size()-i-1]){
          p=1;
          break;
         }
        }
        if(!p){
         ll c=count(all(s),'0');
         if(c%2 && c!=1){
             cout<<"ALICE"<<endl;
         }
         else{
             cout<<"BOB"<<endl;
         }
     }
     else{
      if(n%2 && s[n/2]=='0'){
       ll c=count(all(s),'0');
       if(c==1) cout<<"BOB"<<endl;
       if(c==2) cout<<"DRAW"<<endl;
       if(c>=3) cout<<"ALICE"<<endl;
      }
      else cout<<"ALICE"<<endl;
     }
    }
 
    return 0;
}