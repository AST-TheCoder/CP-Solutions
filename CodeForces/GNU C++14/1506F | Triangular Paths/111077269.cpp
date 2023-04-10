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
 
  pair<ll,ll> a[n];
  for(ll i=0;i<n;i++) cin>>a[i].first;
  for(ll i=0;i<n;i++) cin>>a[i].second;
  sort(a,a+n);
  ll ans=0;
 
  ll r=1,c=1;
  for(ll i=0;i<n;i++){
   ll x=(r-c)/2;
   ll y=(a[i].first-a[i].second)/2;
   if(x==y){
    if(2*y==a[i].first-a[i].second){
     ans+=a[i].first-r;
    }
   }
   else{
    ans+=y-x;
   }
   r=a[i].first,c=a[i].second;
  }
  cout<<ans<<endl;
 
 }
 return 0;
}