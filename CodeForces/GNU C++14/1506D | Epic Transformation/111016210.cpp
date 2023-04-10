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
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll mx=1,c=1,ans=0;
  sort(a,a+n);
  for(ll i=1;i<=n;i++){
   if(a[i]==a[i-1]) c++;
   else{
    mx=max(mx,c);
    c=1;
   }
  }mx=max(mx,c);
  if(n%2){
   ans++;
   mx--;
   n--;
  }
  if(mx>n/2){
   ans+=(mx-(n-mx));
  }
  cout<<ans<<endl;
 }
 
 return 0;
}