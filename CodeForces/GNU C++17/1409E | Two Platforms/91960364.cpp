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
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,k,ans=0;
  cin>>n>>k;
 
  ll x[n+1],y,a[n+1],max_pref[n+1],max_suff[n+1];
  for(ll i=1;i<=n;i++) cin>>x[i];
  for(ll i=1;i<=n;i++) cin>>y;
 
  sort(x+1,x+n+1);
  for(ll i=1;i<=n;i++){
   ll c=upper_bound(x+1,x+n+1,x[i]+k)-x;
   a[i]=c-i;
  }
 
  max_pref[1]=a[1];
  for(ll i=2;i<=n;i++) max_pref[i]=max(max_pref[i-1],a[i]);
  max_suff[n]=a[n];
  for(ll i=n-1;i>=1;i--) max_suff[i]=max(max_suff[i+1],a[i]);
  
  for(ll i=1;i<=n;i++){
   ll c1=upper_bound(x+1,x+n+1,x[i]+k)-x;
   ll c2=lower_bound(x+1,x+n+1,x[i]-k)-x;
   c2--;
 
   ll p=0,q=0;
   if(c2>0) p=max_pref[c2];
   if(c1<=n) q=max_suff[c1];
   ans=max(ans,a[i]+max(p,q));
  }
  cout<<ans<<endl;
 }
 
 return 0;
}