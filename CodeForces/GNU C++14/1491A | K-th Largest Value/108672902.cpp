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
 
 ll n,q;
 cin>>n>>q;
 
 ll a[n+1],o=0;
 for(ll i=1;i<=n;i++){
  cin>>a[i];
  if(a[i]) o++;
 }
 
 while(q--){
  ll t;
  cin>>t;
  if(t==1){
   ll x;
   cin>>x;
   if(a[x]==1) o--,a[x]=0;
   else o++,a[x]=1;
  }
  else{
   ll x;
   cin>>x;
   if(o>=x) cout<<1<<endl;
   else cout<<0<<endl;
  }
 }
 
 return 0;
}