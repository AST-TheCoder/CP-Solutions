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
#define     an              400007
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
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
    st s;
    cin>>s;
 
    ll c[n],r[n],d[n],a[n],i,ans=maxi,idx=-1,h[n]={0};
    for(i=0;i<n;i++){
        cin>>c[i];
        r[i]=0;d[i]=0;a[i]=0;
    }
 
    for(i=n-1;i>=0;i--){
        if(s[i]=='d'){
            d[i]+=c[i];
            if(i+1!=n) d[i]+=d[i+1];
        }
        else if(s[i]=='r' && i+1!=n && d[i+1]>0){
            r[i]+=c[i]+r[i+1];
            r[i]=min(r[i],d[i+1]);
        }
        else if(s[i]=='a' && i+1!=n && r[i+1]>0){
            a[i]+=c[i]+a[i+1];
            a[i]=min(a[i],r[i+1]);
        }
        else if(s[i]=='h' && i+1!=n && a[i+1]>0){
            h[i]+=c[i]+h[i+1];
            h[i]=min(h[i],a[i+1]);
            idx=i;
        }
        if(i+1!=n){
            if(s[i]!='h') h[i]+=h[i+1];
            if(s[i]!='a') a[i]+=a[i+1];
            if(s[i]!='r') r[i]+=r[i+1];
            if(s[i]!='d') d[i]+=d[i+1];
        }
    }
 
    if(idx==-1){
        cout<<0<<endl;
        End;
    }
    ans=min(min(h[0],a[0]),min(r[0],d[0]));
    cout<<ans<<endl;
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/