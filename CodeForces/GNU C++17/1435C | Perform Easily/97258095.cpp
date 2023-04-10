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
 
 ll a[6];
 for(ll i=0;i<6;i++) cin>>a[i];
 
 vector<pair<ll,ll>> x;
 ll n,ans=Max;
 cin>>n;
 ll c[n];
 memset(c,0,sizeof(c));
 for(ll i=0;i<n;i++){
  ll p;
  cin>>p;
  for(ll j=0;j<6;j++){
   x.pb({p-a[j],i});
  }
 }
 
 sort(all(x));
 set<ll> p;
 
 for(ll i=0,j=0;i<x.size();i++){
  if(!c[x[i].second]){
   p.insert(x[i].second);
  }
  c[x[i].second]++;
  while(p.size()==n){
   ans=min(ans,x[i].first-x[j].first);
   c[x[j].second]--;
   if(!c[x[j].second]){
    p.erase(x[j].second);
   }
   j++;
  }
 }
 
 cout<<ans<<endl;
 
 return 0;
}