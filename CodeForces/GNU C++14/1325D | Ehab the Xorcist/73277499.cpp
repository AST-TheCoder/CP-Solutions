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
 
ll dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
ll dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
ll X[]= {0,0,1,-1,1,1,-1,-1};
ll Y[]= {1,-1,0,0,1,-1,1,-1};
 
/********************** START **********************/
 
ll a[100],b[100];
 
int main()
{
 
 ll u,v;
 cin>>u>>v;
 
 if(v==0){
  if(!u) cout<<0<<endl;
  else cout<<-1<<endl;
  End;
 }
 
 for(ll i=1;i<100;i++){
  a[i]=u%2;
  u/=2;
  b[i]=v%2;
  v/=2;
 }
 for(ll i=99;i>0;i--){
  if(a[i]==0){
   b[i-1]+=(b[i]*2);
   b[i]=0;
  }
  else{
   if(b[i]==0){
    cout<<-1<<endl;
    End;
   }
   b[i-1]+=((b[i]-1)*2);
   b[i]=1;
  }
 }
 
 for(ll i=1;i<100;i++){
  if(a[i-1]%2){
   if(b[i-1]==0){
    cout<<-1<<endl;
    End;
   }
   b[i]+=((b[i-1]-1)/2);
   b[i-1]=1;
  }
  else{
   b[i]+=(b[i-1]/2);
   b[i-1]=0;
  }
  if(a[i]%2!=b[i]%2){
   if(i==1){
    cout<<-1<<endl;
    End;
   }
   if(b[i]==0){
    cout<<-1<<endl;
    End;
   }
   b[i-1]+=2;
   b[i]--;
  }
 }
 for(ll i=1;i<100;i++){
  if(a[i]%2!=b[i]%2){
   cout<<-1<<endl;
   End;
  }
 }
 Vector ans;
 ll x=1;
 
 while(x){
  x=0;
  ll c=1,q=0;
  for(ll i=1;i<100;i++){
   //cout<<b[i]<<" ";
   if(b[i]){
    b[i]--;
    if(b[i]) x=1;
    q+=c;
   }
   c*=2;
  }
  //cout<<endl;
  ans.pb(q);
 }
 
 cout<<ans.size()<<endl;
 for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/