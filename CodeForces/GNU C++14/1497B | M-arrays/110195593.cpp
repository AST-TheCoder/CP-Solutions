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
  ll n,m;
  cin>>n>>m;
 
  ll a[m];
  memset(a,0,sizeof(a));
  for(ll i=0;i<n;i++){
   ll x;
   cin>>x;
   a[x%m]++;
  }
  ll ans=0;
  if(a[0]) ans++;
  for(ll i=1;i<=m/2;i++){
   if(a[i] || a[m-i]){
    if(!a[i] || !a[m-i]) ans+=a[i]+a[m-i];
    else{
     ans++;
     if(max(a[i],a[m-i])>min(a[i],a[m-i])+1){
      ll x=max(a[i],a[m-i])-min(a[i],a[m-i])-1;
      ans+=x;
     }
    }
   }
  }
  cout<<ans<<endl;
 }
 
 
 return 0;
}