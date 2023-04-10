//Bismillahir Rahmanir Rahim//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)
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
#define     range           10000007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
#define     min_heap        priority_queue <ll, vector<ll>, greater<ll> >
#define     ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>  //*(x.find_by_order(k)),x.order_of_key(k)
 
/*************** #Template FUNCTIONS# **************/
 
/// ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){ll x=GCD(a,b);return (a/x)*b;}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[range];Vector pr;void sieve(){for(ll i=2;i*i<range;i++){if(!sc[i]){for(ll j=i*i;j<range;j+=i) sc[j]=1;}}pr.pb(2);for(ll i=3;i<range;i+=2) if(!sc[i]) pr.pb(i);}
/// Pair pf[range];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].F=pr[i];pf[u].S=c;u++;}}if(n>1){pf[u].F=n;pf[u].S=1;}}
/// Vector de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pb(i);de.pb(n%i);}}if((i-1)*(i-1)==n) de.pb(i-1);sort(all(de));}
/// bool check(ll n,ll i){return (bool)(n&(1<<i));}
/// ll set(ll n,ll i){return n=(n|(1<<i));}
 
/// ll dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
/// ll dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
/// ll X[]= {0,0,1,-1};
/// ll Y[]= {1,-1,0,0};
 
/********************** START **********************/
 
Vector a[500006],s[3];
 
int main()
{
 
    fast;
    ll n,e;
    cin>>n>>e;
    for(ll i=0;i<e;i++){
     ll u,v;
     cin>>u>>v;
     a[u].pb(v);
     a[v].pb(u);
    }
    for(ll i=1;i<=n;i++){
     sort(all(a[i]));
    }
    ll sn=3,x[n+1],c[n+1];
    mem(x,0);
    mem(c,0);
    while(sn--){
     for(ll i=1;i<=n;i++){
      if(x[i]==0){
       for(ll j=1;j<=n;j++){
        if(!binary_search(all(a[i]),j)){
         //cout<<binary_search(all(a[i]),j)<<endl;
         s[sn].pb(j);
         x[j]=sn+1;
         c[j]++;
        }
       }
       break;
      }
     }
 }
 
 /*while(sn!=3){
  for(ll i=0;i<s[sn].size();i++) cout<<s[sn][i]<<" ";
  cout<<endl;
  sn++;
 }*/
 
 if(!s[0].size() || !s[1].size() || !s[2].size()) cout<<-1<<endl;
 else{
  for(ll i=1;i<=n;i++){
   if(c[i]!=1){
    cout<<-1<<endl;
    End;
   }
  }
  for(ll i=1;i<=n;i++){
   for(ll j=0;j<a[i].size();j++){
    if(x[i]==x[a[i][j]]){
     cout<<-1<<endl;
     End;
    }
   }
  }
 
  if((ll)s[0].size()*(ll)s[1].size()+(ll)s[1].size()*(ll)s[2].size()+(ll)s[2].size()*(ll)s[0].size()>e){
   cout<<-1<<endl;
   End;
  }
 
  for(ll i=1;i<=n;i++){
   cout<<x[i]<<" ";
  }
 }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/
 