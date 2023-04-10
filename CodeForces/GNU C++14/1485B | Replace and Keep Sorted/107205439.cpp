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
 
 //ll t;
 //scanf("%lli",&t);
 
 //while(t--){
  ll n,q,k;
  scanf("%lli %lli %lli",&n,&q,&k);
  ll a[n+1];
  ll s[n+1];
  s[0]=0;
  for(ll i=1;i<=n;i++){
   scanf("%lli",&a[i]);
   if(i!=1){
    s[i-1]=2*(a[i]-a[i-1]-1);
   }
  }
  for(ll i=1;i<n;i++){
   s[i]+=s[i-1];
  }
  while(q--){
   ll l,r;
   scanf("%lli %lli",&l,&r);
   ll ans=s[r-1]-s[l-1]+a[l]-1+k-a[r];
   cout<<ans<<endl;
  }
 //}
 
 return 0;
}