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
 
 ll ok=0;
 
 ll a[n+1];
 ll l[n+1],r[n+1];
 for(ll i=1;i<=n;i++){
  cin>>a[i];
  r[i]=l[i]=-1;
 }
 
 ll s=1,m=1;
 for(ll i=2;i<=n;i++){
  if(a[i-1]>a[i]){
   m=max(s,m);
   l[i-1]=s;
   s=1;
  }
  else s++;
 }l[n]=s;
 
 s=1;
 for(ll i=n-1;i>=1;i--){
  if(a[i+1]>a[i]){
   m=max(s,m);
   r[i+1]=s;
   s=1;
  }
  else s++;
 }r[1]=s;
 
 ll cnt=0;
 for(ll i=1;i<=n;i++){
  if(l[i]==m || r[i]==m) cnt++;
 }
 if(cnt>1 || m%2==0){
  cout<<0<<endl;
  return 0;
 }
 for(ll i=1;i<=n;i++){
  if(l[i]==m && r[i]==m){
   cout<<1<<endl;
   return 0;
  }
 }
 cout<<0<<endl;
 
 return 0;
}