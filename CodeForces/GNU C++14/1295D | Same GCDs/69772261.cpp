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
#define     range           100007
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
Vector x;
vector<Pair> v;
void per(ll c,ll i,ll t)
{
 if(i>=x.size()) return;
 v.pb(mp(t+1,c*x[i]));
 per(c*x[i],i+1,t+1);
 per(c,i+1,t);
}
 
int main()
{
 fast;
 
 sieve();
 ll t;
 cin>>t;
 
 while(t--){
  x.clear();
  v.clear();
  ll a,m,i=0,ans=0,q;
  cin>>a>>m;
  ll g=__gcd(a,m);
  q=m;
  m/=g;
  ans=((a+q)/g)-((a-1)/g);
  Vector pf;
  while(m!=1 && i<primes.size()){
   if(m%primes[i]==0){
    m/=primes[i];
    pf.pb(primes[i]);
   }
   else{
    i++;
   }
  }
  if(m!=1) pf.pb(m);
  else pf.pb(primes[i]);
  for(i=0;i<pf.size();i++){
   if(i==0 || pf[i]!=pf[i-1]) x.pb(pf[i]);
  }
  per(1,0,0);
  sort(all(v));
  for(i=0;i<v.size();i++){
   if(v[i].F%2){
    ans-=((a+q)/(g*v[i].S))-((a-1)/(g*v[i].S));
   }
   else{
    ans+=((a+q)/(g*v[i].S))-((a-1)/(g*v[i].S));
   }
  }
  cout<<ans-1<<endl;
 }
 
 End;
}
 
/*****************  ALHAMDULILLAH  *****************/