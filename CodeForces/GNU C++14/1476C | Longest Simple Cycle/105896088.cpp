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
 
  ll c[n+1],a[n+1],b[n+1];
  for(ll i=1;i<=n;i++) cin>>c[i];
  for(ll i=1;i<=n;i++) cin>>a[i];
  for(ll i=1;i<=n;i++) cin>>b[i];
 
  ll ans=0;
  for(ll i=2,s=abs(a[2]-b[2])+1;i<=n;i++){
   if(i!=2){
    if(a[i]==b[i]) s=1;
    else s+=min(a[i],b[i])+(c[i-1]-max(a[i],b[i])+1);
    s=max(s,abs(a[i]-b[i])+1);
   }
   ans=max(ans,s+c[i]);
   //cout<<i<<" "<<" "<<s+c[i]<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
 }
 
 return 0;
}