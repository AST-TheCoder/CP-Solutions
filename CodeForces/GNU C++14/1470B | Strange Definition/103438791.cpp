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
 
 vector<ll> pr;
 ll mark[1001];
 memset(mark,0,sizeof(mark));
 for(ll i=2;i<=1000;i++){
  if(!mark[i]){
   //cout<<i<<endl;
   pr.pb(i);
   for(ll j=i;j<=1000;j+=i){
    mark[j]=1;
   }
  }
 }
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll n;
  scanf("%lli",&n);
  ll a[n+1];
  for(ll i=1;i<=n;i++){
   scanf("%lli",&a[i]);
   for(ll j=0;j<pr.size() && pr[j]*pr[j]<=a[i];j++){
    ll val=pr[j]*pr[j];
    while(a[i]%val==0) a[i]/=val;
   }
   //cout<<a[i]<<endl;
  }
  sort(a+1,a+n+1);
  ll ini=1,even=0,c=1;
  for(ll i=2;i<=n;i++){
   if(a[i]==a[i-1]) c++;
   else{
    ini=max(ini,c);
    if(c%2==0 || a[i-1]==1) even+=c;
    c=1;
   }
  }
  ini=max(ini,c);
  if(c%2==0 || a[n]==1) even+=c;
  ll q;
  scanf("%lli",&q);
  while(q--){
   ll w;
   scanf("%lli",&w);
   if(!w) printf("%lli\n",ini);
   else printf("%lli\n",max(ini,even));
  }
 }
 
 return 0;
}