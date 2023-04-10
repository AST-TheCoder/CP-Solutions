//Bismillahir Rahmanir Rahim//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     in1(X)          scanf("%lli",&(X))
#define     ins(S)          scanf("%s",(S))
#define     out(X)          printf("%lli",(X))
#define     outs(S)         printf("%s",(S))
#define     printnl         printf("\n")
#define     End             return 0
#define     ll              long long int
#define     Pair            pair<ll,ll>
#define     F               first
#define     S               second
#define     all(v)          v.begin(),v.end()
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     Max             1000000000000000014
#define     Min             -1000000000000000014
#define     mod             1000000007
#define     range           1000007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
#define     min_heap        priority_queue <ll, vector<ll>, greater<ll> >
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;//*(x.find_by_order(i)),x.order_of_key(k)
 
/*************** #Template FUNCTIONS# **************/
 
ll pc;void PrintCase(){printf("Case %lli:\n",++pc);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll power(ll n,ll p){if(p==0) return 1;if(p==1)return n;if(p%2)return power(n,p-1)*n;else{ll x=power(n,p/2);return x*x;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
ll Check(ll n,ll i){return (n&(1LL<<i));}
ll Set(ll n,ll i){return (n|(1LL<<i));}
ll status[(ll)range/64+5];Vector primes;void sieve(){for(ll i=3;i<=sqrt(range);i+=2){if(Check(status[i/64],i%64)==0){for(ll j=i*i;j<range;j+=2*i){status[j/64]=Set(status[j/64],j%64);}}}primes.pb(2);for(ll i=3;i<range;i+=2)if(Check(status[i/64],i%64)==0)primes.pb(i);}
 
ll dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
ll dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
ll X[]= {0,0,1,-1,1,1,-1,-1};
ll Y[]= {1,-1,0,0,1,-1,1,-1};
 
/********************** START **********************/
 
ll par[range],comp[range];
 
ll find_par(ll x)
{
 if(par[x]==x) return x;
 return par[x]=find_par(par[x]);
}
 
int main()
{
 
 ll n,m;
 cin>>n>>m;
 pair<ll,Pair> a[n];
 mem(a,0);
 for(ll i=1;i<n;i++){
  cin>>a[i].S.F>>a[i].S.S>>a[i].F;
 }
 
 sort(a,a+n);
 
 Pair q[m+2];
 for(ll i=1;i<=m;i++){
  cin>>q[i].F;
  q[i].S=i;
 }
 q[m+1].F=Max;
 
 sort(q+1,q+m+1);
 
 ll j=1,ans[m+5];
 mem(ans,0);
 for(ll i=1;i<=n;i++) par[i]=i,comp[i]=1;
 for(ll i=1;i<n;i++){
  while(q[j].F<a[i].F){
   j++;
   ans[j]=ans[j-1];
  }
  ll u=find_par(a[i].S.F);
  ll v=find_par(a[i].S.S);
  ans[j]=ans[j]-((comp[u]*(comp[u]-1))/2)-((comp[v]*(comp[v]-1))/2);
  par[v]=u;
  comp[u]+=comp[v];
  ans[j]+=((comp[u]*(comp[u]-1))/2);
 }
 for(j++;j<=m;j++) ans[j]=ans[j-1];
 
 ll x[m+1];
 for(ll i=1;i<=m;i++){
  x[q[i].S]=ans[i];
 }
 
 for(ll i=1;i<=m;i++) cout<<x[i]<<" ";
 
 End;
}
 
/*****************  ALHAMDULILLAH  *****************/