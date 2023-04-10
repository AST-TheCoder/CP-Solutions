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
ll lr[507][507];
ll ud[507][507];
 
ll dp[507][507][17];
 
ll solve(ll i,ll j,ll k){
 if(!k) return 0;
 if(dp[i][j][k]!=-1) return dp[i][j][k];
 ll x=INT_MAX,y=INT_MAX,p=INT_MAX,q=INT_MAX;
 if(lr[i][j-1]!=INT_MAX) x=solve(i,j-1,k-1)+lr[i][j-1];
 if(lr[i][j]!=INT_MAX) y=solve(i,j+1,k-1)+lr[i][j];
 if(ud[i-1][j]!=INT_MAX) p=solve(i-1,j,k-1)+ud[i-1][j];
 if(ud[i][j]!=INT_MAX) q=solve(i+1,j,k-1)+ud[i][j];
 
 dp[i][j][k]=min(min(x,y),min(p,q));
 return dp[i][j][k];
}
 
int main()
{   
 
 ll n,m,k;
 cin>>n>>m>>k;
 
 memset(dp,-1,sizeof(dp));
 
 for(ll i=1;i<=n;i++){
  for(ll j=0;j<=m;j++){
   if(!j || j==m) lr[i][j]=INT_MAX;
   else cin>>lr[i][j];
  }
 }
 
 for(ll i=0;i<=n;i++){
  for(ll j=1;j<=m;j++){
   if(!i || i==n) ud[i][j]=INT_MAX;
   else cin>>ud[i][j];
  }
 }
 
 if(k%2){
  for(ll i=1;i<=n;i++){
   for(ll j=1;j<=m;j++){
    cout<<-1<<" ";
   }cout<<endl;
  }
  return 0;
 }
 
 for(ll i=1;i<=n;i++){
  for(ll j=1;j<=m;j++){
   cout<<solve(i,j,k/2)*2<<" ";
  }cout<<endl;
 }
 
 return 0;
}