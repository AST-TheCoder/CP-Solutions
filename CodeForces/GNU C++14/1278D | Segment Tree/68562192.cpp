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
 
Vector a[range];
ll c;
bool vis[range];
void dfs(ll u)
{
 vis[u]=1;
 c++;
 for(ll i=0;i<a[u].size();i++){
  ll v=a[u][i];
  if(!vis[v]){
   dfs(v);
  }
 }
}
 
int main()
{
 
 ll n,e=0;
 in1(n);
 Pair y[n];
 for(ll i=0;i<n;i++){
  in1(y[i].F);
  in1(y[i].S);
 }
 
 sort(y,y+n);
 
 ordered_set<ll> x;
 ordered_set<Pair> v;
 for(ll i=0;i<n;i++){
  e+=(x.order_of_key(y[i].S)-x.order_of_key(y[i].F));
  x.insert(y[i].S);
  if(e>n-1){
   printf("NO\n");
   End;
  }
 }
  
 for(ll i=0;i<n;i++){
  ll d=v.order_of_key(mp(y[i].S,i+1));
  ordered_set<Pair>::iterator it=v.find_by_order(v.order_of_key(mp(y[i].F,i+1)));
  //cout<<*it<<" "<<d<<endl;
  for(ll j=v.order_of_key(mp(y[i].F,i+1));j<d;j++){
   Pair p=*it;
   a[p.S].pb(i+1);
   a[i+1].pb(p.S);
   it++;
   //cout<<*it<<endl;
  }
  v.insert(mp(y[i].S,i+1));
 }
 
 dfs(1);
 
 if(c!=n) printf("NO\n");
 else printf("YES\n");
 
 End;
}
 
/*****************  ALHAMDULILLAH  *****************/