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
#define     range           4000007
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
 
ll ans[range],o[range],c[range],cnt;
string s;
 
void build(ll n,ll l,ll r)
{
 //cnt++;
 //cout<<cnt<<endl;
 if(l==r){
  if(s[l]=='(') o[n]=1;
  else c[n]=1;
  return;
 }
 ll mid=(l+r)/2,left=2*n,right=2*n+1;
 build(left,l,mid);
 build(right,mid+1,r);
 ans[n]=ans[2*n]+ans[2*n+1]+min(o[2*n],c[2*n+1])*2;
 o[n]=o[2*n+1]+o[2*n]-min(o[2*n],c[2*n+1]);
 c[n]=c[2*n]+c[2*n+1]-min(o[2*n],c[2*n+1]);
}
 
pair<ll,Pair> query(ll n,ll l,ll r,ll i,ll j)
{
 if(j<l || i>r) return mp(0,mp(0,0));
 if(i<=l && j>=r){
  return mp(ans[n],mp(o[n],c[n]));
 }
 ll mid=(l+r)/2,left=2*n,right=2*n+1;
 pair<ll,Pair> x=query(left,l,mid,i,j);
 pair<ll,Pair> y=query(right,mid+1,r,i,j);
 return mp(x.F+y.F+min(x.S.F,y.S.S)*2,mp(x.S.F+y.S.F-min(x.S.F,y.S.S),x.S.S+y.S.S-min(x.S.F,y.S.S)));
}
 
int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 //char a[range/4];
 cin>>s;
 //scanf("%s",a);
 //for(ll i=0;i<strlen(a);i++) s+=a[i];
  //cout<<s<<endl;
 
 build(1,0,s.size()-1);
 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll i,j;
  scanf("%lli %lli",&i,&j);
  pair<ll,Pair> x;
  x=query(1,0,s.size()-1,i-1,j-1);
  printf("%lli\n",x.F);
 }
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/