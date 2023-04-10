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
 
 ll n;
 cin>>n;
 
 ll a[n+1],b[n+1],ans=0;
 for(ll i=1;i<=n;i++) cin>>a[i];
 for(ll j=1;j<=n;j++){
  cin>>b[j];
  ans+=a[j]*b[j];
 }
 
 ll dp[n+1][n+1],mx=0;
 memset(dp,0,sizeof(dp));
 
 for(ll l=1;l<n;l++){
  for(ll i=1,j=i+l;j<=n;i++,j++){
   dp[i][j]=(a[i]-a[j])*(b[j]-b[i]);
   if(l-1) dp[i][j]+=dp[i+1][j-1];
   mx=max(mx,dp[i][j]);
  }
 }
 
 ans+=mx;
 cout<<ans<<endl;
 
    return 0;
}