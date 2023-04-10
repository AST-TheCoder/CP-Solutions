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
#define     range           4000
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
 
string s[51];
 
bool ok(ll i,ll j,ll n,ll m)
{
 if(i==n-1 && j==m-1) return 1;
 s[i][j]='P';
 ll chk=0;
 if(i!=0 && !chk){
  if(s[i-1][j]=='X') chk=1;
  else if(s[i-1][j]=='.' || s[i-1][j]=='G') chk=ok(i-1,j,n,m);
 }
 if(i!=n-1 && !chk){
  if(s[i+1][j]=='X') chk=1;
  else if(s[i+1][j]=='.' || s[i+1][j]=='G') chk=ok(i+1,j,n,m);
 }
 if(j!=0 && !chk){
  if(s[i][j-1]=='X') chk=1;
  else if(s[i][j-1]=='.' || s[i][j-1]=='G') chk=ok(i,j-1,n,m);
 }
 if(j!=m-1 && !chk){
  if(s[i][j+1]=='X') chk=1;
  else if(s[i][j+1]=='.' || s[i][j+1]=='G') chk=ok(i,j+1,n,m);
 }
 if(chk) s[i][j]='X';
 return chk;
}
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,m;
  cin>>n>>m;
  for(ll i=0;i<n;i++) cin>>s[i];
  for(ll i=0;i<n;i++){
   for(ll j=0;j<m;j++){
    if(s[i][j]=='B'){
     if(i!=0){
      if(s[i-1][j]=='G'){
       cout<<"No"<<endl;
       goto read;
      }
      else if(s[i-1][j]=='B');
      else s[i-1][j]='#';
     }
     if(i!=n-1){
      if(s[i+1][j]=='G'){
       cout<<"No"<<endl;
       goto read;
      }
      else if(s[i+1][j]=='B');
      else s[i+1][j]='#';
     }
     if(j!=0){
      if(s[i][j-1]=='G'){
       cout<<"No"<<endl;
       goto read;
      }
      else if(s[i][j-1]=='B');
      else s[i][j-1]='#';
     }
     if(j!=m-1){
      if(s[i][j+1]=='G'){
       cout<<"No"<<endl;
       goto read;
      }
      else if(s[i][j+1]=='B');
      else s[i][j+1]='#';
     }
    }
   }
  }
  for(ll i=0;i<n;i++){
   for(ll j=0;j<m;j++){
    if(s[i][j]=='G'){
     if(!ok(i,j,n,m)){
      cout<<"No"<<endl;
      goto read;
     }
    }
   }
  }
 
  cout<<"Yes"<<endl;
 }
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/