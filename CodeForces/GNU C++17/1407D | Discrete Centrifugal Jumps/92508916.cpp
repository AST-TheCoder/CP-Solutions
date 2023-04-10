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
 
 pair<ll,ll> h[n+1];
 vector<ll> idx[n+1],idy[n+1];
 set<ll> jump[n+1];
 
 for(ll i=1;i<=n;i++){
  cin>>h[i].first;
  h[i].second=i;
 }
 
 sort(h+1,h+n+1);
 ll c=1;
 for(ll i=1;i<=n;i++){
  idx[c].pb(h[i].second);
  idy[c].pb(-h[i].second);
  if(i!=n && h[i].first!=h[i+1].first) c++;
 }
 
 ordered_set<ll> x,y,p,q;
 for(ll i=c;i>=1;i--){
  for(ll j=0;j<idx[i].size();j++){
   x.insert(idx[i][j]);
  }
  for(ll j=0;j<idx[i].size();j++){
   ll id=x.order_of_key(idx[i][j])+1;
   if(id<x.size()) jump[idx[i][j]].insert(*x.find_by_order(id));
  }
 }
 
 for(ll i=c;i>=1;i--){
  for(ll j=0;j<idy[i].size();j++){
   p.insert(idy[i][j]);
  }
  for(ll j=0;j<idy[i].size();j++){
   ll id=p.order_of_key(idy[i][j])+1;
   if(id<p.size()) jump[-1*(*p.find_by_order(id))].insert(-idy[i][j]);
  }
 }
 
 for(ll i=1;i<=c;i++){
  for(ll j=0;j<idx[i].size();j++){
   y.insert(idx[i][j]);
  }
  for(ll j=0;j<idx[i].size();j++){
   ll id=y.order_of_key(idx[i][j])+1;
   if(id<y.size()) jump[idx[i][j]].insert(*y.find_by_order(id));
  }
 }
 
 for(ll i=1;i<=c;i++){
  for(ll j=0;j<idy[i].size();j++){
   q.insert(idy[i][j]);
  }
  for(ll j=0;j<idy[i].size();j++){
   ll id=q.order_of_key(idy[i][j])+1;
   if(id<q.size()) jump[-1*(*q.find_by_order(id))].insert(-idy[i][j]);
  }
 }
 
 ll ans[n+1];
 ans[1]=0;
 for(ll i=2;i<=n;i++) ans[i]=n;
 
 for(ll i=1;i<=n;i++){
  for(auto x:jump[i]){
   ans[x]=min(ans[x],ans[i]+1);
  }
 }
 
 cout<<ans[n]<<endl;
 
 return 0;
}