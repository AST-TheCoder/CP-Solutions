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
#define     printnl         printf("\n")
#define     printsp         printf(" ");
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
#define     maxi            1000000000000000014
#define     mini            -100000000000014
#define     mod             1000000007
#define     an              507
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
 
/*************** #Template FUNCTIONS# **************/
 
/// ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){ll x=GCD(a,b);return (a/x)*b;}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};
 
/********************** START **********************/
 
ll n;
pairl num[an],dist[an][an],dp[an][3];
 
ll get(ll x,ll y,ll p){
 return x*n*3+y*3+p;
}
 
ll in(ll x,ll y){
 return (x>=0 && y>=0 && x<n && y<n);
}
 
pairl operator +(const pairl &a, const pairl &b){
    return mp(a.fr + b.fr, a.se + b.se);
}
 
int main()
{
 
    fast;
 
    cin>>n;
    ll a[n][n],i,j;
    for(i=0;i<n;i++){
     for(j=0;j<n;j++){
      cin>>a[i][j];
      a[i][j]--;
      num[a[i][j]]=mp(i,j);
     }
    }
 
    for(i=0;i<an;i++){
     for(j=0;j<an;j++){
      if(i!=j) dist[i][j]=mp(maxi,maxi);
     }
    }
 
    for(ll x=0;x<n;x++){
     for(ll y=0;y<n;y++){
      for(i=0;i<8;i++){
       if(in(x+dx[i],y+dy[i])){
        dist[get(x,y,0)][get(x+dx[i],y+dy[i],0)]=mp(1,0);
       }
      }
      for(i=1-n;i<n;i++){
       if(in(x+i,y+i)){
        dist[get(x,y,1)][get(x+i,y+i,1)]=mp(1,0);
       }
       if(in(x+i,y-i)){
        dist[get(x,y,1)][get(x+i,y-i,1)]=mp(1,0);
       }
      }
      for(i=0;i<n;i++){
       if(in(x,i)){
        dist[get(x,y,2)][get(x,i,2)]=mp(1,0);
       }
       if(in(i,y)){
        dist[get(x,y,2)][get(i,y,2)]=mp(1,0);
       }
      }
      for(i=0;i<3;i++){
       for(j=0;j<3;j++){
        if(i!=j){
         dist[get(x,y,i)][get(x,y,j)]=mp(1,1);
        }
       }
      }
     }
    }
 
    for(ll k=0;k<an;k++){
     for(i=0;i<an;i++){
      for(j=0;j<an;j++){
       dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
     }
    }
 
    for(i=1;i<n*n;i++){
     for(j=0;j<3;j++){
      dp[i][j]=mp(maxi,maxi);
     }
    }
 
    for(i=0;i<n*n-1;i++){
     for(j=0;j<3;j++){
      for(ll k=0;k<3;k++){
       dp[i+1][k]=min(dp[i+1][k],dp[i][j]+dist[get(num[i].fr,num[i].se,j)][get(num[i+1].fr,num[i+1].se,k)]);
      }
     }
    }
 
    pairl ans=min(dp[n*n-1][0],min(dp[n*n-1][1],dp[n*n-1][2]));
    cout<<ans.fr<<" "<<ans.se<<endl;
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/