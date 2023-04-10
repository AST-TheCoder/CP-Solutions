#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
 
  ll x[n];
  for(ll i=0;i<n;i++) cin>>x[i];
 
  vector<ll> a,b;
  for(ll i=0;i<n;i++){
   ll v;
   cin>>v;
   if(x[i]) a.pb(v);
   else b.pb(v);
  }
 
  if(a.size()>b.size()) swap(a,b);
  sort(all(a));
  sort(all(b),greater<ll>());
  ll ans=0;
  for(ll i=0;i<a.size();i++){
   ans+=2*a[i];
  }
  for(ll i=0;i<b.size();i++){
   if(i<a.size()) ans+=2*b[i];
   else ans+=b[i];
  }
  if(a.size()==b.size()){
   if(a[0]<=b[b.size()-1]) ans-=a[0];
   else ans-=b[b.size()-1];
  }
  cout<<ans<<endl;
 }
 
 return 0;
}