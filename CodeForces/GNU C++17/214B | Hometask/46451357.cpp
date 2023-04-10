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
 
ll x[3];
 
int main()
{
 
    ll n;
    cin>>n;
 
    ll a[n],p=0,q=0,i;
 
    for(i=0;i<n;i++){
        cin>>a[i];
        x[a[i]%3]++;
    }
 
    sort(a,a+n,greater<ll>());
 
    if(a[n-1]!=0){
        cout<<-1;
        End;
    }
 
    p=x[0];
    ll u=(x[1]/3),vx=(x[2]/3);
    u*=3,vx*=3;
    q=min(x[1]-u,x[2]-vx);
 
    if(x[1] && x[1]-u==0 && x[2]-vx==2){
        u-=3;q=2;
    }
    else if(x[1]-u==2 && x[2] && x[2]-vx==0){
        vx-=3;q=2;
    }
 
    if(q<0) q=0;
 
    if(p+q+u+vx==0){
        cout<<-1;
        End;
    }
 
    ve v;
 
    ll o=0,t=0;
 
    for(i=0;i<n;i++){
        if(a[i]%3==1 && o<q+u){
            v.pi(a[i]);
            o++;
        }
        else if(a[i]%3==2 && t<q+vx){
            v.pi(a[i]);
            t++;
        }
        else if(a[i]%3==0) v.pi(a[i]);
    }
 
    if(v[0]==0){
        cout<<0;
        End;
    }
 
    for(i=0;i<v.size();i++) cout<<v[i];
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/