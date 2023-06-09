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
#define     mod             998244353
#define     range           200007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.1415926535897
#define     min_heap        priority_queue <Pair, vector<Pair>, greater<Pair> >
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;//*(x.find_by_order(i)),x.order_of_key(k)
 
/*************** #Template FUNCTIONS# **************/
 
ll pc;void PrintCase(){printf("Case %lli:\n",++pc);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n)%mod;if(p%2)return (bigmod(n,p-1)*n)%mod;else{ll x=bigmod(n,p/2);return (x*x)%mod;}}
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
 
Vector a[range];
ll vis[range];
ll child[range],ind[range],ans;
priority_queue<Pair> pq;
 
void DFS(ll u,ll chk)
{
 if(chk==1){
  for(ll i=0;i<a[u].size();i++){
   ll v=a[u][i];
   if(!vis[v]){
    vis[v]=vis[u]+1;
    DFS(v,chk);
    child[u]+=child[v]+1;
   }
  }
  pq.push(mp(vis[u]-child[u]-1,u));
 }
 else{
  ll c=0;
  for(ll i=0;i<a[u].size();i++){
   ll v=a[u][i];
   if(!vis[v]){
    vis[v]=vis[u]+1;
    if(ind[v]) c+=child[v]+1;
    else DFS(v,chk);
   }
  }
  ans+=(c*vis[u]);
  //cout<<c<<" "<<vis[u]<<" "<<u<<endl;
 }
}
 
int main()
{
 
 ll n,k;
 cin>>n>>k;
 
 for(ll i=1;i<n;i++){
  ll x,y;
  cin>>x>>y;
  a[x].pb(y);
  a[y].pb(x);
 }
 vis[1]=1;
 DFS(1,1);
 //for(ll i=1;i<=n;i++) cout<<vis[i]<<endl;
 while(k--){
  Pair x=pq.top();
  pq.pop();
  ind[x.S]=1;
  //cout<<x.S<<endl;
 }
 mem(vis,0);
 vis[1]=1;
 DFS(1,0);
 
 cout<<ans<<endl;
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/