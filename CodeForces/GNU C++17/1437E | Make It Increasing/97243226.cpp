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
 
 ll n,k,ans=0;
 cin>>n>>k;
 
 ll a[n+2];
 a[0]=-Max;
 vector<ll> x;
 x.pb(0LL);
 for(ll i=1;i<=n;i++){
  cin>>a[i];
  a[i]-=i;
 }
 a[n+1]=Max;
 
 for(ll i=1;i<=k;i++){
  ll p;
  cin>>p;
  x.pb(p);
 }x.pb(n+1);
 
 for(ll i=1;i<x.size();i++){
  vector<ll> v;
  if(a[x[i]]<a[x[i-1]]){
   cout<<-1<<endl;
   return 0;
  }
  for(ll j=x[i-1]+1;j<x[i];j++){
   if(a[x[i-1]]<=a[j] && a[j]<=a[x[i]]){
    ll idx=upper_bound(all(v),a[j])-v.begin();
    if(idx==v.size()) v.pb(a[j]);
    else v[idx]=a[j];
   }
  }
  ans+=(x[i]-x[i-1]-v.size()-1);
 }
 
 cout<<ans<<endl;
 
 return 0;
}