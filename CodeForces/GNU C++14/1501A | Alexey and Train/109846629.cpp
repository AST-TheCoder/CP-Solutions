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
  cin>>n;
 
  ll a[n+1],b[n+1];
  a[0]=b[0]=0;
 
  for(ll i=1;i<=n;i++){
   cin>>a[i]>>b[i];
  }
  ll m[n+1];
  for(ll i=1;i<=n;i++){
   cin>>m[i];
   m[i]+=a[i]-b[i-1];
  }
 
  ll ed=0;
 
  for(ll i=1;i<=n;i++){
   ed+=m[i];
   if(i!=n){
    ed+=(b[i]-a[i]+1)/2;
    if(ed<b[i]) ed=b[i];
   }
  }
 
  cout<<ed<<endl;
 
 }
 
 return 0;
}