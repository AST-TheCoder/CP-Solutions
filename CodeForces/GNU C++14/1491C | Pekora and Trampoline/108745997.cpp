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
  ll a[n+1],c[n+1],ans=0LL;
  memset(c,0,sizeof(c));
  for(ll i=1;i<=n;i++) cin>>a[i];
  for(ll i=1;i<=n;i++){
   ans+=max(0LL,a[i]-1LL-c[i]);
   if(i<n && c[i]>=a[i]){
    c[i+1]+=(c[i]-a[i]+1);
   }
   //cout<<i<<" "<<a[i]<<" "<<c[i]<<endl;
   for(ll j=i+2;j<=n && a[i]>1;j++,a[i]--){
    c[j]++;
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}