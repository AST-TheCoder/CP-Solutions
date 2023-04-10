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
 
 read:
 while(t--){
  ll n,k;
  cin>>n>>k;
 
  ll a[n],c[n],s=0;
  for(ll i=0;i<n;i++){
   cin>>a[i];
   c[i]=0;
  }
 
  vector<ll> ans;
  for(ll i=0;i<n;i++){
   ll ok=0;
   for(ll j=0;j<n;j++){
    if(c[j]) continue;
    if(s+a[j]!=k){
     c[j]=1;
     s+=a[j];
     ok=1;
     ans.pb(a[j]);
     break;
    }
   }
   if(!ok){
    cout<<"NO"<<endl;
    goto read;
   }
  }
 
  cout<<"YES"<<endl;
  for(ll i=0;i<n;i++){
   cout<<ans[i]<<" ";
  }cout<<endl;
 }
 
    return 0;
}