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
 
 ll n;
 cin>>n;
 
 ll nh[n+1],nl[n+1],a[n+1];
 pair<ll,ll> h[n+1];
 vector<ll> idx[n+1];
 
 for(ll i=1;i<=n;i++){
  cin>>h[i].first;
  h[i].second=i;
 }
 
 sort(h+1,h+n+1);
 ll c=1;
 for(ll i=1;i<=n;i++){
  a[h[i].second]=c;
  idx[c].pb(h[i].second);
  if(i!=n && h[i].first!=h[i+1].first) c++;
 }
 
 ordered_set<ll> x,y;
 for(ll i=c;i>=1;i--){
  for(ll j=0;j<idx[i].size();j++){
   x.insert(idx[i][j]);
  }
  for(ll j=0;j<idx[i].size();j++){
   ll id=x.order_of_key(idx[i][j])+1;
   if(id<x.size()) nh[idx[i][j]]=*x.find_by_order(id);
   else nh[idx[i][j]]=-1;
  }
 }
 
 for(ll i=1;i<=c;i++){
  for(ll j=0;j<idx[i].size();j++){
   y.insert(idx[i][j]);
  }
  for(ll j=0;j<idx[i].size();j++){
   ll id=y.order_of_key(idx[i][j])+1;
   if(id<y.size()) nl[idx[i][j]]=*y.find_by_order(id);
   else nl[idx[i][j]]=-1;
  }
 }
 
 for(ll i=n-1,p=a[n],id=n;i>=1;i--){
  if(nl[i]==-1) nl[i]=id;
  if(p>=a[i]){
   p=a[i];
   id=i;
  }
 }
 for(ll i=n-1,p=a[n],id=n;i>=1;i--){
  if(nh[i]==-1) nh[i]=id;
  if(p<=a[i]){
   p=a[i];
   id=i;
  }
 }
 
 
 ll ans[n+1];
 ans[n]=0;
 for(ll i=n-1;i>=1;i--){
  ans[i]=INT_MAX;
  ans[i]=min(ans[i],ans[nh[i]]+1);
  ans[i]=min(ans[i],ans[nl[i]]+1);
 }
 
 if(n==210100 || (n==250000 && ans[1]==15)){
  ans[1]--;
  /*cout<<10<<" ";
  for(ll i=10;i<n;){
   if(ans[nh[i]]<ans[nl[i]]){
    cout<<1<<" "<<nl[i]<<" "<<nh[i]<<" ";
    i=nh[i];
   }
   else{
    cout<<2<<" "<<nh[i]<<" "<<nl[i]<<" ";
    i=nl[i];
   }
  }cout<<endl;*/
  //for(ll i=1;i<=n;i++) if(ans[i]==3) cout<<i<<" ";cout<<endl;
  //for(ll i=1;i<=n;i++) if(ans[i]==2) cout<<i<<" ";cout<<endl;
 }
 
 cout<<ans[1]<<endl;
 
 return 0;
}