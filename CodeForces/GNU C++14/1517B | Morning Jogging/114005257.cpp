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
 
  ll a[n][m];
  ll c[n][m];
  ll p[n][m];
  for(ll i=0;i<n;i++){
   for(ll j=0;j<m;j++){
    cin>>a[i][j];
    c[i][j]=0;
   }
   sort(a[i],a[i]+m);
  }
  for(ll k=0;k<m;k++){
   ll mi=INT_MAX,idx=-1,idy=-1;
   for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
     if(a[i][j]<mi && !c[i][j]){
      mi=a[i][j];
      idx=i;
      idy=j;
      break;
     }
    }
   }
   p[idx][k]=mi;
   c[idx][idy]=1;
   for(ll i=0;i<n;i++){
    if(i==idx) continue;
    for(ll j=m-1;j>=0;j--){
     if(!c[i][j]){
      c[i][j]=1;
      p[i][k]=a[i][j];
      break;
     }
    }
   }
  }
 
  for(ll i=0;i<n;i++){
   for(ll j=0;j<m;j++)
    cout<<p[i][j]<<" ";
   cout<<endl;
  }
 
 }
 
 return 0;
}