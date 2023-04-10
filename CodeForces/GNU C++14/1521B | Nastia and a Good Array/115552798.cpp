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
  ll a[n+1],id=-1,mn=INT_MAX;
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   if(a[i]<mn){
    id=i;
    mn=a[i];
   }
  }
  cout<<n-1<<endl;
  for(ll i=1;i<=n;i++){
   if(i!=id){
    if(abs(i-id)%2) cout<<i<<" "<<id<<" "<<a[id]+1<<" "<<a[id]<<endl;
    else cout<<i<<" "<<id<<" "<<a[id]<<" "<<a[id]<<endl;
   }
  }
 }
 
    return 0;
}