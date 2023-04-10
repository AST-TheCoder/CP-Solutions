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
#define     mod             998244353
#define     an              300007
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
vector<pairl> x;
st a[100];
ll ans=maxi,n;
 
void check(ll r,ll c)
{
    a[r][c]='2';
    //cout<<r<<" "<<c<<" "<<n<<endl;
    if(r-1>=0){
        if(a[r-1][c]=='0') check(r-1,c);
        else if(a[r-1][c]=='1') x.pi(mp(r,c));
        //cout<<1<<endl;
    }
    if(r+1<n){
        if(a[r+1][c]=='0') check(r+1,c);
        else if(a[r+1][c]=='1') x.pi(mp(r,c));
        //cout<<2<<endl;
    }
    if(c-1>=0){
        if(a[r][c-1]=='0') check(r,c-1);
        else if(a[r][c-1]=='1') x.pi(mp(r,c));
        //cout<<3<<endl;
    }
    if(c+1<n){
        if(a[r][c+1]=='0') check(r,c+1);
        else if(a[r][c+1]=='1') x.pi(mp(r,c));
        //cout<<4<<endl;
    }
}
 
void own(ll r,ll c)
{
    r++;c++;
    for(ll i=0;i<x.size();i++){
        ll p=x[i].fr+1;
        ll q=x[i].se+1;
        ans=min(ans,((p-r)*(p-r))+((q-c)*(q-c)));
        //cout<<ans<<" "<<p<<" "<<q<<" "<<r<<" "<<c<<endl;
    }
}
 
void solve(ll r,ll c)
{
    a[r][c]='2';
    if(r-1>=0){
        if(a[r-1][c]=='0') solve(r-1,c);
        else if(a[r-1][c]=='1') own(r,c);
    }
    if(r+1<n){
        if(a[r+1][c]=='0') solve(r+1,c);
        else if(a[r+1][c]=='1') own(r,c);
    }
    if(c-1>=0){
        if(a[r][c-1]=='0') solve(r,c-1);
        else if(a[r][c-1]=='1') own(r,c);
    }
    if(c+1<n){
        if(a[r][c+1]=='0') solve(r,c+1);
        else if(a[r][c+1]=='1') own(r,c);
    }
}
 
int main()
{
 
    fast;
 
    ll r,c,p,q,i;
    cin>>n>>r>>c>>p>>q;
 
    r--,c--,p--,q--;
    for(i=0;i<n;i++) cin>>a[i];
 
    check(r,c);
    if(a[p][q]=='2'){
        cout<<0<<endl;
        End;
    }
    solve(p,q);
 
    cout<<ans<<endl;
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/