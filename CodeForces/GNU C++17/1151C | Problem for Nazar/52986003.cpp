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
#define     an              200007
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
 
/*************** #Template FUNCTIONS# **************/
 
/// ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
int main()
{
 
    fast;
 
    ll l,r,i,x=0,y=0,a=0,b=0;
    cin>>l>>r;
    l--;
 
    for(i=0;;i++){
        ll p=pow(2,i);
        if(x+y+p<l){
            if(!(i%2)) x+=p;
            else y+=p;
        }
        else{
            if(!(i%2)) x+=(l-(x+y));
            else y+=(l-(x+y));
            break;
        }
    }
 
    if(x%2){
        a+=(2*x)-1;
        a%=mod;
        x--;
    }
    if(y%2){
        a+=(2*y);
        a%=mod;
        y--;
    }
 
    a+=(((2*x)%mod)*((x/2)%mod))%mod;
    a%=mod;
    a+=(((2*y+2)%mod)*((y/2)%mod))%mod;
    a%=mod;
 
    x=0,y=0;
 
    for(i=0;;i++){
        ll p=pow(2,i);
        if(x+y+p<r){
            if(!(i%2)) x+=p;
            else y+=p;
        }
        else{
            if(!(i%2)) x+=(r-(x+y));
            else y+=(r-(x+y));
            break;
        }
    }
 
    if(x%2){
        b+=(2*x)-1;
        b%=mod;
        x--;
    }
    if(y%2){
        b+=(2*y);
        b%=mod;
        y--;
    }
 
    b+=(((2*x)%mod)*((x/2)%mod))%mod;
    b%=mod;
    b+=(((2*y+2)%mod)*((y/2)%mod))%mod;
    b%=mod;
 
    ll ans=(b-a+(2*mod))%mod;
    cout<<ans<<endl;
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/