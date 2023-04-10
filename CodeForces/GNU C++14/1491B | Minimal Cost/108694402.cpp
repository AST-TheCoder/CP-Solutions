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
  ll n,u,v;
  cin>>n>>u>>v;
 
  ll a[n],d=0;
  for(ll i=0;i<n;i++){
   cin>>a[i];
   if(i){
    d=max(d,abs(a[i]-a[i-1]));
   }
  }
  ll ans;
  //cout<<d<<endl;
  if(d>=2) ans=0;
  else if(d==1){
   ans=min(u,v);
  }
  else{
   ans=min(u,v)+v;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}