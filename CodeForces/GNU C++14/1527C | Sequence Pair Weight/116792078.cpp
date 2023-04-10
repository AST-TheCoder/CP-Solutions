#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
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
  ll a[n+1];
  vector<pair<ll,ll>> x;
  ll cnt[n+1];
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   cnt[i]=0;
   x.pb({a[i],i});
  }
  sort(all(x));
  ll c=1;
  a[x[0].second]=1;
  for(ll i=1;i<x.size();i++){
   if(x[i].first!=x[i-1].first) c++;
   a[x[i].second]=c;
  }
  //for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
  ll ans=0;
  for(ll i=1;i<=n;i++){
   ans+=(n-i+1)*cnt[a[i]];
   cnt[a[i]]+=i;
  }
  cout<<ans<<endl;
 }
 
    return 0;
}