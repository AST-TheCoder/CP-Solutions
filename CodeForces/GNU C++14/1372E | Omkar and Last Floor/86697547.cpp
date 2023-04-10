#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;//*(x.find_by_order(i)),x.order_of_key(k)
 
int main()
{
 
 ll n,m;
 cin>>n>>m;
 
 ll mat[n+5][m+5];
 ll interval_no[n+5];
 pair<ll,ll> interval[n+5][m+5];
 ll dp[m+5][m+5];
 memset(dp,0,sizeof(dp));
 
 for(ll i=1;i<=n;i++){
  cin>>interval_no[i];
  for(ll j=1;j<=interval_no[i];j++){
   cin>>interval[i][j].first>>interval[i][j].second;
   for(ll p=interval[i][j].first;p<=interval[i][j].second;p++){
    mat[i][p]=j;
   }
  }
 }
 
 for(ll j=1;j<=m;j++){
  for(ll l=1,r=l+j-1;r<=m;l++,r++){
   for(ll k=l;k<=r;k++){
    ll cnt=0;
    for(ll i=1;i<=n;i++){
     ll intrvl=mat[i][k];
     if(interval[i][intrvl].first>=l && interval[i][intrvl].second<=r) cnt++;
    }
    dp[l][r]=max(dp[l][r],dp[l][k-1]+(cnt*cnt)+dp[k+1][r]);
   }
  }
 }
 
 cout<<dp[1][m]<<endl;
 
    return 0;
}