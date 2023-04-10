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
#define     range           1000007
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
 
 ll n,m,p,a=0,b=0;
 vector<Pair> f,s,o,e;
 in1(n);in1(m);in1(p);
 
 for(ll i=1;i<=n;i++){
  ll t,x,y;
  in1(t);in1(x);in1(y);
  if(x && y) o.pb(mp(t,i));
  else if(x) f.pb(mp(t,i));
  else if(y) s.pb(mp(t,i));
  else e.pb(mp(t,i));
 }
 
 sort(all(o));
 sort(all(f));
 sort(all(s));
 sort(all(e));
 
 ll t=0,fs=f.size(),ss=s.size(),os=o.size(),es=e.size(),i=0,j=0,k=0,l=0;
 for(i=0,j=0,k=0;a<p || b<p;){
  if(i==fs && j==ss && k==os) break;
  if(a!=p && b!=p && k<os){
   if(i==fs || j==ss){
    t+=o[k].F;
    k++;
    a++,b++;
   }
   else if(f[i].F+s[j].F>o[k].F){
    t+=o[k].F;
    k++;
    a++,b++;
   }
   else{
    t+=(f[i].F+s[j].F);
    i++,j++;
    a++,b++;
   }
  }
  else{
   while(a<p && i<fs){
    t+=f[i].F;
    a++;
    i++;
   }
   while(b<p && j<ss){
    t+=s[j].F;
    b++;
    j++;
   }
   break;
  }
 }
 
 if(a<p || b<p){
  printf("-1\n");
  End;
 }
 
 while(i+j+k>m && k<o.size() && i && j){
  i--,j--;
  t+=(o[k].F-f[i].F-s[j].F);
  k++;
 }
 
 if(i+j+k>m){
  printf("-1\n");
  End;
 }
 
 while(i+j+k+l<m){
  ll x=Max;
  if(i<fs) x=min(x,f[i].F);
  if(j<ss) x=min(x,s[j].F);
  if(k<os) x=min(x,o[k].F);
  if(l<es) x=min(x,e[l].F);
 
  t+=x;
 
  if(k<os && o[k].F==x) k++,a++,b++;
  else if((i<fs && f[i].F==x) || (j<ss && s[j].F==x)){
   if(i<fs && j<ss && f[i].F==s[j].F){
    if(a<=b) i++,a++;
    else j++,b++;
   }
   else if(i<fs && f[i].F==x) i++,a++;
   else j++,b++;
  }
  else l++;
 }
 
 
 while(l<es){
  ll x=-1,id=-1;
  if(k && a>p && b>p && o[k-1].F>=e[l].F && o[k-1].F>=x) x=o[k-1].F,id=1;
  if(i && a>p && f[i-1].F>=e[l].F && f[i-1].F>=x) x=f[i-1].F,id=2;
  if(j && b>p && s[j-1].F>=e[l].F && s[j-1].F>=x) x=s[j-1].F,id=3;
 
  if(x==-1) break;
  t+=(e[l].F-x);
  l++;
 
  if(id==1) k--,a--,b--;
  if(id==2) i--,a--;
  if(id==3) j--,b--;
 }
 
 while(i<fs){
  ll x=-1,id=-1;
  if(l && e[l-1].F>=f[i].F && e[l-1].F>=x) x=e[l-1].F,id=2;
  if(k && b>p && o[k-1].F>=f[i].F && o[k-1].F>=x) x=o[k-1].F,id=1;
  if(j && b>p && s[j-1].F>=f[i].F && s[j-1].F>=x) x=s[j-1].F,id=3;
 
  if(x==-1) break;
  t+=(f[i].F-x);
  i++;a++;
 
  if(id==1) k--,a--,b--;
  if(id==2) l--;
  if(id==3) j--,b--;
 }
 
 while(j<ss){
  ll x=-1,id=-1;
  if(l && e[l-1].F>=s[j].F && e[l-1].F>=x) x=e[l-1].F,id=2;
  if(k && a>p && o[k-1].F>=s[j].F && o[k-1].F>=x) x=o[k-1].F,id=1;
  if(i && a>p && f[i-1].F>=s[j].F && f[i-1].F>=x) x=f[i-1].F,id=3;
 
  if(x==-1) break;
  t+=(s[j].F-x);
  j++;b++;
 
  if(id==1) k--,a--,b--;
  if(id==2) l--;
  if(id==3) i--,a--;
 }
 
 while(k<os){
  ll x=-1,id=-1;
  if(l && e[l-1].F>=o[k].F && e[l-1].F>=x) x=e[l-1].F,id=2;
  if(i && f[i-1].F>=o[k].F && f[i-1].F>=x) x=f[i-1].F,id=1;
  if(j && s[j-1].F>=o[k].F && s[j-1].F>=x) x=s[j-1].F,id=3;
 
  if(x==-1) break;
  t+=(o[k].F-x);
  k++;a++;b++;
 
  if(id==1) i--,a--;
  if(id==2) l--;
  if(id==3) j--,b--;
 }
 
 out(t);printnl;
 while(i--) cout<<f[i].S<<" ";
 while(j--) cout<<s[j].S<<" ";
 while(k--) cout<<o[k].S<<" ";
 while(l--) cout<<e[l].S<<" ";
 
 
    End;
}
 
/*****************  ALHAMDULILLAH  *****************/