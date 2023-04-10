#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
pair<ll,ll> take(ll w,ll n,ll m,ll e1,ll e2){
 ll x=min(w/e1,n);
 w-=(e1*x);
 ll y=min(w/e2,m);
 return mp(x,y);
}
 
ll sum(pair<ll,ll> x,pair<ll,ll> y){
 return x.first+x.second+y.first+y.second;
}
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  ll w1,w2;
  cin>>w1>>w2;
  ll n,m;
  cin>>n>>m;
  ll e1,e2;
  cin>>e1>>e2;
 
  if(e1>e2){
   swap(e1,e2);
   swap(n,m);
  }
 
  ll ans=0;
 
  for(ll i=0;i<=n;i++){
   pair<ll,ll> x=take(w1,i,m,e1,e2);
   pair<ll,ll> y=take(w2,n-x.first,m-x.second,e1,e2);
 
   ans=max(ans,sum(x,y));
  }
  
  cout<<ans<<endl;
 }
 
 return 0;
}