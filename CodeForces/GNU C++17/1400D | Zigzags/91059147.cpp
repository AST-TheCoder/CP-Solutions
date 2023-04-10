#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll n;
  scanf("%lli",&n);
  ll a[n+1];
  for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);
 
  ll cnt[n+1][n+1],ans=0;
  memset(cnt,0,sizeof(cnt));
 
  for(ll j=n;j>=1;j--){
   ll k=j+1;
   for(ll l=k+1;l<=n;l++){
    cnt[a[k]][a[l]]++;
   }
 
   for(ll i=1;i<j;i++){
    ans+=cnt[a[i]][a[j]];
   }
  }
 
  printf("%lli\n",ans);
 }
 
 return 0;
}