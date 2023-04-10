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
#define     range           300007
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
 
int main()
{
 
 ll t;
 in1(t);
 
 while(t--){
  ll p,q,r;
  vector<Pair> x;
  in1(p);
  in1(q);
  in1(r);
  for(ll i=0;i<p;i++){
   ll k;
   in1(k);
   x.pb(mp(k,1));
  }
  for(ll i=0;i<q;i++){
   ll k;
   in1(k);
   x.pb(mp(k,2));
  }
  for(ll i=0;i<r;i++){
   ll k;
   in1(k);
   x.pb(mp(k,3));
  }
  sort(all(x));
  ll ans=-1;
  
  for(ll k=1;k<=6;k++){
   if(k==1) p=1,q=2,r=3;
   if(k==2) p=1,q=3,r=2;
   if(k==3) p=2,q=1,r=3;
   if(k==4) p=2,q=3,r=1;
   if(k==5) p=3,q=1,r=2;
   if(k==6) p=3,q=2,r=1;
   ll c[4];
   mem(c,-1);
   for(ll i=0;i<x.size();i++){
    c[x[i].S]=i;
    if(c[p]!=-1 && c[q]!=-1 && c[r]!=-1){
     if(r==x[i].S){
      for(ll j=c[p]+1;j<c[r];j++){
       if(x[j].S==q){
        ll chk=((x[c[p]].F-x[j].F)*(x[c[p]].F-x[j].F))+((x[j].F-x[c[r]].F)*(x[j].F-x[c[r]].F))+((x[c[r]].F-x[c[p]].F)*(x[c[r]].F-x[c[p]].F));
        
        if(ans==-1) ans=chk;
        else ans=min(ans,chk);
       }
      }
      c[p]=-1;
     }
    }
   }
  }
 
  out(ans);printnl;
 }
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/