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
  ll n;
  ll mod=1000000007;
  scanf("%lli",&n);
  ll c[65],a[n+1];
  memset(c,0,sizeof(c));
  for(ll i=1;i<=n;i++){
   scanf("%lli",&a[i]);
   ll x=a[i],j=0;
   while(x){
    if(x%2) c[j]++;
    j++;
    x/=2;
   }
  }
  ll ok[n+1];
  for(ll i=1;i<=n;i++){
   ll temp=0;
   for(ll k=0,ch=1;k<=60;k++){
      if(a[i]&(1LL<<k)){
       temp+=n*ch;
      }
      else{
       temp+=c[k]*ch;
      }
      ch*=2;
      ch%=mod;
      temp%=mod;
     }
     ok[i]=temp;
  }
 
  ll ans=0;
 
  for(ll i=1;i<=n;i++){
   ll x=a[i],p=1,j=0;
   while(x){
    if(x%2){
     ll temp=ok[i];
     //cout<<temp<<endl;
     temp*=p;
     temp%=mod;
     temp*=c[j];
     temp%=mod;
     //cout<<temp<<endl;
     ans+=temp;
     ans%=mod;
    }
    j++;
    x/=2;
    p*=2;
    p%=mod;
   }
  }
  printf("%lli\n",ans);
 }
 
 return 0;
}