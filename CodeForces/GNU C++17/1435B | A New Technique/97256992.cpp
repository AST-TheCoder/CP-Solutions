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
  ll n,m;
  cin>>n>>m;
 
  vector<ll> row[n+1],column[m+1];
  for(ll i=1;i<=n;i++){
   row[i].pb(0LL);
   for(ll j=1;j<=m;j++){
    ll x;
    cin>>x;
    row[i].pb(x);
   }
  }
 
  for(ll i=1;i<=m;i++){
   column[i].pb(0LL);
   for(ll j=1;j<=n;j++){
    ll x;
    cin>>x;
    column[i].pb(x);
   }
  }
 
  ll l=1;
  for(ll k=1;k<=n;k++){
   for(ll i=1;i<=n;i++){
    if(column[l][k]==row[i][1]){
     for(ll j=1;j<=m;j++){
      cout<<row[i][j]<<" ";
     }cout<<endl;
     break;
    }
    if(i==n){
     l++;
     k--;
    }
   }
  }
 }
 
 return 0;
}