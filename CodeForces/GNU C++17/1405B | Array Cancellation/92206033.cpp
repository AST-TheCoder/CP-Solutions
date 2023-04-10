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
  ll n;
  cin>>n;
  ll a[n+1];
  for(ll i=1;i<=n;i++) cin>>a[i];
 
  for(ll i=1,j=1;i<=n;i++){
   if(a[i]>0){
    if(j<=i) j=i+1;
    for(;j<=n;j++){
     if(a[j]<0){
      if(-a[j]<a[i]){
       a[i]+=a[j];
       a[j]=0;
      }
      else{
       a[j]+=a[i];
       a[i]=0;
       break;
      }
     }
    }
   }
  }
 
  ll ans=0;
  for(ll i=1;i<=n;i++){
   //cout<<a[i]<<" ";
   if(a[i]>0) ans+=a[i];
  }
  cout<<ans<<endl;
 }
 
 return 0;
}