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
 
 ll a[n+1];
 for(ll i=1;i<=n;i++) cin>>a[i];
 
 ll p[n+1][n+1];
 memset(p,-1,sizeof(p));
 for(ll i=1;i<=n;i++){
  ll x=a[i];
  ll c=0;
  for(ll u=i,v=i;c<x;c++){
   p[u][v]=x;
   if(v-1<1 || p[u][v-1]!=-1) u++;
   else v--;
  }
 }
 
 for(ll i=1;i<=n;i++){
  for(ll j=1;j<=i;j++){
   cout<<p[i][j]<<" ";
  }cout<<endl;
 }
 
 return 0;
}