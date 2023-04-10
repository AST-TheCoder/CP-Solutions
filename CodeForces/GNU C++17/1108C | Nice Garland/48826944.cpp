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
#define     maxi            1000000000000014
#define     mini            -100000000000014
#define     mod             998244353
#define     an              10007
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
 
    ll n;
    cin>>n;
    st s,p[7];
    cin>>s;
 
    ll m=maxi,c=0,x=0,i;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='G') c++;
        p[1]+='G';
        if(i+1<n && s[i+1]!='R') c++;
        if(i+1<n) p[1]+='R';
        if(i+2<n && s[i+2]!='B') c++;
        if(i+2<n) p[1]+='B';
    }
 
    if(c<m){
        m=c;
        x=1;
    }
 
    c=0;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='G') c++;
        p[2]+='G';
        if(i+1<n && s[i+1]!='B') c++;
        if(i+1<n) p[2]+='B';
        if(i+2<n && s[i+2]!='R') c++;
        if(i+2<n) p[2]+='R';
    }
 
    if(c<m){
        m=c;
        x=2;
    } 
    c=0;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='B') c++;
        p[3]+='B';
        if(i+1<n && s[i+1]!='G') c++;
        if(i+1<n) p[3]+='G';
        if(i+2<n && s[i+2]!='R') c++;
        if(i+2<n) p[3]+='R';
    }
 
    if(c<m){
        m=c;
        x=3;
    } 
    c=0;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='B') c++;
        p[4]+='B';
        if(i+1<n && s[i+1]!='R') c++;
        if(i+1<n) p[4]+='R';
        if(i+2<n && s[i+2]!='G') c++;
        if(i+2<n) p[4]+='G';
    }
 
    if(c<m){
        m=c;
        x=4;
    } 
    c=0;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='R') c++;
        p[5]+='R';
        if(i+1<n && s[i+1]!='B') c++;
        if(i+1<n) p[5]+='B';
        if(i+2<n && s[i+2]!='G') c++;
        if(i+2<n) p[5]+='G';
    }
 
    if(c<m){
        m=c;
        x=5;
    }
    c=0;
 
    for(i=0;i<n;i+=3){
        if(s[i]!='R') c++;
        p[6]+='R';
        if(i+1<n && s[i+1]!='G') c++;
        if(i+1<n) p[6]+='G';
        if(i+2<n && s[i+2]!='B') c++;
        if(i+2<n) p[6]+='B';
        //cout<<c<<endl;
    }
    if(c<m){
        m=c;
        x=6;
    }
    c=0;
//cout<<x<<endl;
    cout<<m<<endl;
    cout<<p[x]<<endl;
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/