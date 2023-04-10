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
 
ll cnt[20000007];
 
int main()
{ 
 
 for(ll i=2;i<20000007;i++){
  if(cnt[i]==0){
   for(ll j=i;j<20000007;j+=i){
    cnt[j]++;
   }
  }
 }
 
 int t;
 scanf("%lli",&t);
 
 while(t--){
  ll c,d,x,ans=0;
  scanf("%lli %lli %lli",&c,&d,&x);
  vector<ll> div;
  for(ll i=1;i*i<=x;i++){
   if(!(x%i)){
    div.pb(i);
    if(i!=x/i) div.pb(x/i);
   }
  }
  for(ll i=0;i<div.size();i++){
   ll gcd=div[i];
   if((d+(x/gcd))%c==0){
    ll lcm=(d+(x/gcd))/c;
    if(lcm==1) ans+=1;
    else ans+=pow(2,cnt[lcm]);
   }
  }
  printf("%lli\n",ans);
 }
 
 
 return 0;
}