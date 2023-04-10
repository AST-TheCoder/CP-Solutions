#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll cnt[3001][3001];
vector<ll> pos[3001];
 
int main()
{
 
 ll t;
 scanf("%lli",&t);
 
 read:
 while(t--){
  ll n;
  scanf("%lli",&n);
 
  for(ll i=1;i<=n;i++){
   pos[i].clear();
   for(ll j=1;j<=n;j++){
    cnt[i][j]=0;
   }
  }
  ll a[n+1];
  for(ll i=1;i<=n;i++){
   scanf("%lli",&a[i]);
   pos[a[i]].pb(i);
   for(ll j=1;j<=n;j++){
    cnt[i][j]=cnt[i-1][j];
   }
   cnt[i][a[i]]++;
  }
 
  ll ans=0;
 
  for(ll v=1;v<=n;v++){
   ll x[n+1],i;
   memset(x,0,sizeof(x));
   for(i=0;i<((ll)pos[v].size())-1;i++){
     //cout<<"check"<<" "<<i<<endl;
    ll p=pos[v][i],q=pos[v][i+1];
    for(ll j=1;j<=n;j++){
     if(j==v) continue;
     x[j]+=(cnt[q][j]-cnt[p][j])*(i+1);
     ans+=(x[j]*(cnt[n][j]-cnt[q][j]));
    }
   }
   if(i>=3) ans+=((i+1)*i*(i-1)*(i-2))/24;
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}