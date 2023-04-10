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
 
  ll ans[n+1][n+1];
  for(ll i=1;i<=n;i++){
   for(ll j=1;j<=n;j++){
    ans[i][j]=-2;
   }
  }
 
  ll w=(n-1)/2,d=(n-1)%2;
  for(ll j=1;j<=n;j++){
   ll a=w,b=d;
   for(ll i=1;i<=n;i++){
    if(i==j || ans[i][j]!=-2) continue;
    if(a){
     ans[i][j]=1;
     ans[j][i]=-1;
     a--;
    }
    else if(b){
     ans[i][j]=0;
     ans[j][i]=0;
     b--;
    }
    else{
     ans[i][j]=-1;
     ans[j][i]=1;
    }
   }
  }
 
  
 
  for(ll i=1;i<=n;i++){
   for(ll j=i+1;j<=n;j++){
    cout<<ans[j][i]<<" ";
   }
  }cout<<endl;
 }
 
 return 0;
}