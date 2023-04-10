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
#define     range           3000007
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
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
  ll a[n];
  Vector x;
  for(ll i=0;i<n;i++){
   cin>>a[i];
   if(i%2) x.pb(a[i]-a[i-1]);
  }
  ll mx=0,idxi=-1,idxj=-1;
  for(ll i=0;i<x.size();i++){
   if(i) x[i]+=x[i-1];
   if(x[i]<0) x[i]=0;
   if(x[i]>mx){
    mx=x[i];
    idxj=i;
   }
  }
  
  for(ll i=idxj;i>=0;i--){
   if(x[i]==0) break;
   idxi=i;
  }
  idxj*=2;
  idxj++;
  idxi*=2;
 
  ll ans=0;
 
  //cout<<idxi<<" "<<idxj<<endl;
 
  for(ll i=0;i<idxi;i+=2) ans+=a[i];
  for(ll i=idxi+1;i<=idxj && i>=0;i+=2) ans+=a[i];
  for(ll i=idxj+1;i<n;i+=2) ans+=a[i];
 
  x.clear();
  for(ll i=1;i<n;i++){
   if(i%2==0) x.pb(a[i-1]-a[i]);
  }
  mx=0,idxi=-2,idxj=-2;
  for(ll i=0;i<x.size();i++){
   if(i) x[i]+=x[i-1];
   if(x[i]<0) x[i]=0;
   if(x[i]>mx){
    mx=x[i];
    idxj=i;
   }
  }
  
  for(ll i=idxj;i>=0;i--){
   if(x[i]==0) break;
   idxi=i;
  }
  idxj*=2;
  idxj+=2;
  idxi*=2;
  idxi++;
 
  ll ans1=0;
 
  //cout<<idxi<<" "<<idxj<<endl;
 
  for(ll i=0;i<idxi;i+=2) ans1+=a[i];
  for(ll i=idxi;i<idxj && i>=0;i+=2) ans1+=a[i];
  for(ll i=max(idxj+2,0LL);i<n;i+=2) ans1+=a[i];
 
  cout<<max(ans,ans1)<<endl;
 }
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/