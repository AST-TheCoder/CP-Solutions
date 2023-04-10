//Bismillahir Rahmanir Rahim//
#include <bits/stdc++.h>
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
#define     range           400007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.1415926535897
#define     min_heap        priority_queue <ll, vector<ll>, greater<ll> >
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
double start_time,finish_time;void cnt_time(){start_time=clock();}void print_time(){finish_time=(clock()-start_time)/double(CLOCKS_PER_SEC)*1000;printf("Execution Time: %.2f ms\n",finish_time);} 
 
ll dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
ll dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
ll X[]= {0,0,1,-1,1,1,-1,-1};
ll Y[]= {1,-1,0,0,1,-1,1,-1};
 
/********************** START **********************/
 
map<Pair,bool> points;
Pair blc[4*range];
ll pos[range],sum[4*range];
ll n,k,m;
 
void upd(ll node,ll l,ll r,ll id,ll v)
{
 if(id<l || id>r) return;
 if(l==r){
  pos[id]+=v;
  sum[node]=pos[id];
  blc[node].F=pos[id];
  if(pos[id]) blc[node].S=id;
  else blc[node].S=0;
  return;
 }
 
 ll left=2*node,right=2*node+1,mid=(l+r)/2;
 upd(left,l,mid,id,v);
 upd(right,mid+1,r,id,v);
 
 sum[node]=(sum[left]+sum[right]);
 
 if(blc[right].S) blc[node].F=blc[right].F;
 else blc[node].F=0;
 blc[node].S=blc[right].S;
 
 if(blc[left].S){
  if((blc[left].S+blc[left].F+sum[right]-1>=n || blc[left].S+blc[left].F+sum[right]-1>=r) && blc[left].S+blc[left].F+sum[right]-1>=blc[node].S+blc[node].F-1){
   blc[node].F=blc[left].F+sum[right];
   blc[node].S=blc[left].S;
  }
 }
 //if(m==65344) cout<<l<<" "<<r<<" "<<blc[node].S<<" "<<blc[node].F<<" "<<sum[node]<<endl;
}
 
int main()
{
 
 cin>>n>>k>>m;
 
 while(m--){
  ll x,y;
  cin>>x>>y;
 
  ll ys=abs(k-x)+y;
  if(!points[mp(x,y)]){
   points[mp(x,y)]=1;
   upd(1,1,2*n+1,ys,1);
  }
  else{
   points[mp(x,y)]=0;
   upd(1,1,2*n+1,ys,-1);
  }
  ll ans=max(0LL,blc[1].F+blc[1].S-n-1);
  //if(m<5)
  cout<<ans<<endl;
 }
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/