/******************************************************/
/******************************************************/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         Al-Shahriar Tonmoy - Red_Sparkle         **/
/**  Department of Computer Science and Engineering  **/
/**               Barisal University                 **/
/**               It's time to bloom.                **/
/******************************************************/
/******************************************************/
 
#include<bits/stdc++.h>
using namespace std;
#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     in1(X)          scanf("%lli",&(X))
#define     in2(X,Y)        scanf("%lli%lli",&(X),&(Y))
#define     in3(X,Y,Z)      scanf("%lli%lli%lli",&(X),&(Y),&(Z))
#define     ins(S)          scanf("%s",(S))
#define     out(X)          printf("%lli",(X))
#define     outs(S)         printf("%s",(S))
#define     printnl         printf("\n");
#define     End             return 0
#define     ll              long long int
#define     ul              unsigned long long int
#define     dob             double
#define     st              string
#define     pairl           pair<ll,ll>
#define     max3(a,b,c)     max(a,max(b,c))
#define     min3(a,b,c)     min(a,min(b,c))
#define     fr              first
#define     se              second
#define     T               true
#define     F               false
#define     nl              "\n"
#define     all(v)          v.begin(),v.end()
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     maxi            1000000000000014
#define     mini            -100000000000014
#define     mod             1000000007
#define     an              100007
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
/*************** #Template FUNCTIONS# **************/
 
/// ll pc;void PrintCase(){printf("Case #%lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ve a[65],ans;
ll vis[65],n,f,v;
 
void dfs(ll x,ll c){
 
 vis[x]=1;
 
 if(n-c==2 && x<=56 && x%8){
  c+=2;
  ll qq=x%8;v=64;
  while(qq<56) qq+=8;
  ans.pi(v);
  ans.pi(qq);
  ans.pi(x);
  f=1;
  return;
 }
 
 if(x==64){
  if(c==n){
   f=1;
   ans.pi(x);
  }
  vis[x]=0;
  //cout<<c<<endl;
  return;
 }
 
 for(ll i=0;i<a[x].size();i++){
  if(!vis[a[x][i]]){
   if(n<=56 && a[x][i]%8==0 && a[x][i]!=64) continue;
   dfs(a[x][i],c+1);
   if(f==1){
    ans.pi(x);
    return;
   }
  }
 }
 
 vis[x]=0;
 
}
 
int main()
{
 
    for(ll i=1;i<=64;i++){
     ll x=i/8;
     if(i%8==0) x--;
     x*=8;
     for(ll j=x+1;j<=x+8;j++){
      if(j==i) continue;
      a[i].pi(j);
     }
     x=i%8;
     for(ll j=x;j<=64;j+=8){
      if(i==j || !j) continue;
      a[i].pi(j);
     }
    }
    cin>>n;
    
    dfs(1,0);
    //cout<<ans.size()<<endl;
    reverse(all(ans));
 for(ll i=0;i<ans.size();i++){
  char axx='a'-1;
  ll vxx=ans[i]/8+(ans[i]%8!=0);
  ll bxx=ans[i]%8;
  if(!bxx) bxx=8;
  axx+=(char)bxx;
  cout<<axx<<vxx<<" ";
 }
 cout<<endl;
 
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/