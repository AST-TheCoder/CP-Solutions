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
  ll a[n+1];
  for(ll i=1;i<=n;i++){
   cin>>a[i];
  }
  sort(a+1,a+n+1);
  ll dp[n+1][max(2*a[n]+1,n+1)];
  memset(dp,0,sizeof(dp));
 
  for(ll i=1;i<=n;i++){
   ll m=Max;
   for(ll j=i;j<=max(2*a[n],n);j++){
    m=min(m,dp[i-1][j-1]);
    dp[i][j]=abs(j-a[i])+m;
   }
  }
 
  ll ans=Max;
  for(ll i=n;i<=max(2*a[n],n);i++) ans=min(ans,dp[n][i]);
  cout<<ans<<endl;
 }
 
 return 0;
}