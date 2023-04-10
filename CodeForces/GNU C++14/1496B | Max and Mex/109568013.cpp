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
 cin>>t ;
 
 while(t--){
  ll n,k;
  cin>>n>>k;
  ll a[n],mex=0,mx=0;
  for(ll i=0;i<n;i++){
   cin>>a[i];
   mx=max(a[i],mx);
  }
  sort(a,a+n);
  for(ll i=0;i<n;i++){
   if(a[i]!=mex) break;
   mex++;
  }
  if(mex>mx){
   cout<<n+k<<endl;
   continue;
  }
  ll x=(mex+mx)/2+(mex+mx)%2;
  ll ok=0;
  for(ll i=0;i<n;i++){
   if(x==a[i]){
    ok=1;
    break;
   }
  }
  if(!ok && k) cout<<n+1<<endl;
  else cout<<n<<endl;
 }
 
 return 0;
}