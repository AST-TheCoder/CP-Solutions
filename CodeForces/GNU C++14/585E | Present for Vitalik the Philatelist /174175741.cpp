#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int mp1[10000001],mp2[10000001],p[10000001];
bool chk[4000];
vector<ll> pr;
ll mod=1000000007,ans;
 
int main()
{   
 time_t start, end;
 time(&start);
 
 for(ll i=2;i<4000;i++){
  if(!chk[i]){
   pr.pb(i);
   for(ll j=i;j<4000;j+=i){
    chk[j]=1;
   }
  }
 }
 
 ll n,mx=0;
 scanf("%lli",&n);
 
 ll x;
 for(ll i=0;i<n;i++){
  scanf("%lli",&x);
  mx=max(mx,x);
 
  vector<ll> div;
  div.pb(1);
  mp1[1]++;
  for(ll j=0;j<pr.size() && pr[j]*pr[j]<=x;j++){
   if(x%pr[j]) continue;
   ll cnt=0;
   while(x%pr[j]==0){
    cnt++;
    x/=pr[j];
   }
   ll sz=div.size(),val=1;
   for(ll k=0;k<cnt;k++){
    val*=pr[j];
    for(ll id=0;id<sz;id++){
     div.pb(div[id]*val);
     mp1[div[id]*val]++;
    }
   }
  }
  if(x!=1){
   for(ll id=0;id<div.size();id++){
    mp1[div[id]*x]++;
   }
  }
 }
 
 p[0]=1;
 for(ll i=1;i<=mx;i++){
  p[i]=2*p[i-1];
  if(p[i]>=mod) p[i]-=mod;
 }
 
 for(ll i=2;i<=mx;i++){
  if(mp2[i]==-1 || !mp1[i]) continue;
  //cout<<i<<endl;
 
  if(!mp2[i]){
   for(ll j=i;j<=mx;j+=i){
    if((j/i)%i==0) mp2[j]=-1;
    if(mp2[j]!=-1) mp2[j]++;
   }
  }
  ll val=(((ll)p[mp1[i]]-1)*(ll)(n-mp1[i]))%mod;
  if(mp2[i]%2==0) val*=-1;
  //cout<<mp1[i]<<" "<<val<<endl;
  ans=(ans+val+mod)%mod;
 }
 
 
 printf("%lli\n",ans);
 
 return 0;
}