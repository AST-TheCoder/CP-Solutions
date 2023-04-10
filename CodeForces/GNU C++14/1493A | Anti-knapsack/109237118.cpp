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
 scanf("%lli",&t);
 
 while(t--){
  ll n,k;
  cin>>n>>k;
  ll ans=k/2+n-k;
  cout<<ans<<endl;
  for(ll i=k/2+(k%2);i<k;i++){
   cout<<i<<" ";
  }
  for(ll i=k+1;i<=n;i++){
   cout<<i<<" ";
  }cout<<endl;
 }
 
 return 0;
}