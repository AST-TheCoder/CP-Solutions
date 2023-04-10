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
#define     mod             100000007
#define     range           100007
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
 
int main()
{
 
 //fast;
 
 ll a,b,c,d;
 cin>>a>>b>>c>>d;
 
 vector<ll> ans;
 
 if(a>b){
  if(b+1==a && !c && !d){
   ans.pb(0);
   for(ll i=1;i<a;i++){
    ans.pb(1);
    ans.pb(0);
   }
   b=0;
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
 }
 else{
  if((b-a)+d>c && a!=b && a){
   ans.pb(1);
   b--;
  }
  for(ll i=0;i<a;i++){
   ans.pb(0);
   ans.pb(1);
  }
  b-=a;
 }
 //cout<<b<<endl;
 
 if(b>c){
  if(c+1==b && !a && !d){
   ans.pb(1);
   for(ll i=1;i<b;i++){
    ans.pb(2);
    ans.pb(1);
   }
   c=0;
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
 }
 else if(b==c){
  if(!d){
   for(ll i=0;i<b;i++){
    ans.pb(2);
    ans.pb(1);
   }
  }
  else if(!a){
   for(ll i=0;i<b;i++){
    ans.pb(1);
    ans.pb(2);
   }
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
  c=0;
 }
 else{
  if(d>=c-b && !a){
   for(ll i=0;i<b;i++){
    ans.pb(1);
    ans.pb(2);
   }
  }
  else{
   for(ll i=0;i<b;i++){
    ans.pb(2);
    ans.pb(1);
   }
  }
  c-=b;
 }
 
 if(ans.size() && ans[ans.size()-1]==2){
  if(d==c+1){
   d--;
   ans.pb(3);
   for(ll i=0;i<d;i++){
    ans.pb(2);
    ans.pb(3);
   }
   d=0;
  }
  else if(d==c){
   for(ll i=0;i<d;i++){
    ans.pb(3);
    ans.pb(2);
   }
   d=0;
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
 }
 else if(ans.size() && ans[ans.size()-1]==1){
  if(d+1==c){
   c--;
   ans.pb(2);
   for(ll i=0;i<c;i++){
    ans.pb(3);
    ans.pb(2);
   }
   d=0;
  }
  else if(d==c){
   for(ll i=0;i<d;i++){
    ans.pb(2);
    ans.pb(3);
   }
   d=0;
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
 }
 //cout<<ans.size()<<endl;
 
 if(ans.size()==0){
  if(c+1==d){
   d--;
   ans.pb(3);
   for(ll i=0;i<d;i++){
    ans.pb(2);
    ans.pb(3);
   }
   d=0;
  }
  else if(d+1==c){
   c--;
   ans.pb(2);
   for(ll i=0;i<c;i++){
    ans.pb(3);
    ans.pb(2);
   }
   d=0;
  }
  else if(d==c){
   for(ll i=0;i<d;i++){
    ans.pb(2);
    ans.pb(3);
   }
   d=0;
  }
  else{
   cout<<"NO"<<endl;
   End;
  }
 }
 //cout<<ans.size()<<endl;
 
 for(ll i=1;i<ans.size();i++){
  //cout<<ans[i]<<" ";
  if(ans[i]==ans[i-1]){
   cout<<"NO"<<endl;
   End;
  }
 }
 
 cout<<"YES"<<endl;
 for(ll i=0;i<ans.size();i++){
  cout<<ans[i]<<" ";
 }
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/