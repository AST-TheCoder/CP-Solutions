#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n;
  cin>>n;
 
  ll pos=0,neg=0;
  for(ll i=1;i<=n;i++){
   ll x;
   cin>>x;
   if(x>=0) pos+=x;
   else{
    if(pos+x>=0) pos+=x;
    else{
     x+=pos;
     pos=0;
     neg+=x;
    }
   }
  }
 
  cout<<-neg<<endl;
 }
 
 return 0;
}