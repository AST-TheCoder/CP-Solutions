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
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{ 
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  string s;
  cin>>n>>s;
 
  ll z=0,o=0,x=0,y=0;
  for(ll i=0;i<n;i++){
   if(s[i]=='0'){
    z++;
    if(o) x+=o-1;
    o=0;
   }
   else{
    o++;
    if(z) y+=z-1;
    z=0;
   }
  }
 
  cout<<max(x,y)<<endl;
 }
 
 return 0;
}