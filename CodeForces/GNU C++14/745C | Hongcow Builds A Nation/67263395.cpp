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
#define     range           1007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
#define     min_heap        priority_queue <ll, vector<ll>, greater<ll> >
#define     ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>  //*(x.find_by_order(k)),x.order_of_key(k)
 
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
 
ll node[range],edge[range],comp;
Vector a[range];
bool vis[range],c[range],govt[range];
 
void dfs(ll u)
{
 vis[u]=1;
 node[comp]++;
 if(c[u]==1) govt[comp]=1;
 
 for(ll i=0;i<a[u].size();i++){
  edge[comp]++;
  ll v=a[u][i];
  if(!vis[v]){
   dfs(v);
  }
 }
 
}
 
int main()
{
 
 ll n,m,k,ans=0,non_govt_node=0,max_govt_node=0;
 cin>>n>>m>>k;
 
 for(ll i=0;i<k;i++){
  ll x;
  cin>>x;
  c[x]=1;
 }
 
 for(ll i=0;i<m;i++){
  ll x,y;
  cin>>x>>y;
  a[x].pb(y);
  a[y].pb(x);
 }
 
 for(ll i=1;i<=n;i++){
  if(!vis[i]){
   comp++;
   dfs(i);
   edge[comp]/=2;
  }
 }
 
 for(ll i=1;i<=comp;i++){
  ans+=(((node[i]*(node[i]-1))/2)-edge[i]);
  //cout<<i<<" "<<edge[i]<<" "<<node[i]<<endl;
 }
 
 //cout<<ans<<endl;
 
 for(ll i=1;i<=comp;i++){
  if(!govt[i]){
   ans+=non_govt_node*node[i];
   non_govt_node+=node[i];
  }
  else max_govt_node=max(max_govt_node,node[i]);
 }
 
 ans+=max_govt_node*non_govt_node;
 //cout<<comp<<endl;
 cout<<ans<<endl;
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/