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
#define     mod             998244353
#define     an              1001
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
 
int n,a[an][an],t[an][an],f[an][an],dp2[an][an],dp5[an][an],dpf[an][an],dpt[an][an],p1[an][an],p2[an][an];
 
void DP2(ll x,ll y)
{
    ll fr=maxi,dw=maxi;
    if(x==n && y==n){
        dp2[x][y]=t[x][y];
        dp5[x][y]=f[x][y];
        //cout<<2<<" "<<x<<" "<<y<<" "<<dp2[x][y]<<endl;
        return;
    }
    if(dp2[x][y]!=-1){
        //cout<<1<<" "<<x<<" "<<y<<" "<<dp2[x][y]<<endl;
        return;
    }
    if(x+1<=n){
        DP2(x+1,y);
        dw=dp2[x+1][y];
    }
    if(y+1<=n){
        DP2(x,y+1);
        fr=dp2[x][y+1];
    }
    if(fr>dw){
        dp5[x][y]=dp5[x+1][y]+f[x][y];
        p1[x][y]=x+1;
    }
    else if(fr==dw){
        dp5[x][y]=min(dp5[x+1][y],dp5[x][y+1])+f[x][y];
        if(dp5[x+1][y]<=dp5[x][y+1]){
            p1[x][y]=x+1;
        }
        else{
            p1[x][y]=x;
        }
    }
    else{
        dp5[x][y]=dp5[x][y+1]+f[x][y];
        p1[x][y]=x;
    }
    dp2[x][y]=(min(fr,dw))+t[x][y];
    //cout<<0<<" "<<x<<" "<<y<<" "<<dp2[x][y]<<endl;
    return;
}
 
void DP5(ll x,ll y)
{
    ll fr=maxi,dw=maxi;
    if(x==n && y==n){
        dpt[x][y]=t[x][y];
        dpf[x][y]=f[x][y];
        return;
    }
    if(dpf[x][y]!=-1) return;
    if(x+1<=n){
        DP5(x+1,y);
        dw=dpf[x+1][y];
    }
    if(y+1<=n){
        DP5(x,y+1);
        fr=dpf[x][y+1];
    }
    if(fr>dw){
        dpt[x][y]=dpt[x+1][y]+t[x][y];
        p2[x][y]=x+1;
    }
    else if(fr==dw){
        dpt[x][y]=min(dpt[x+1][y],dpt[x][y+1])+t[x][y];
        if(dpt[x+1][y]<=dpt[x][y+1]){
            p2[x][y]=x+1;
        }
        else{
            p2[x][y]=x;
        }
    }
    else{
        dpt[x][y]=dpt[x][y+1]+t[x][y];
        p2[x][y]=x;
    }
    dpf[x][y]=(min(fr,dw))+f[x][y];
    return;
}
 
int main()
{
 
    fast;
 
    ll i,j,c=0,idx=-1;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            ll x=a[i][j];
            if(x==0) idx=i;
            while(!(x%2) && x){
                c++;
                x/=2;
            }
            t[i][j]=c;c=0;
            while(!(x%5) && x){
                c++;
                x/=5;
            }
            f[i][j]=c;c=0;
        }
    }
    mem(dp2,-1);
    mem(dpf,-1);
 
    DP2(1,1);
    DP5(1,1);
    ll ans1=min(dp2[1][1],dp5[1][1]),ans2=min(dpt[1][1],dpf[1][1]);
    if(idx!=-1 && ans1>1 && ans2>1){
        cout<<1<<endl;
        for(i=1;i<idx;i++) cout<<"D";
        for(i=1;i<n;i++) cout<<"R";
        for(i=idx;i<n;i++) cout<<"D";
    }
    else if(ans1<=ans2){
        cout<<ans1<<endl;
        ll x=1,y=1;
        while(x!=n || y!=n){
            if(x!=p1[x][y]){
                cout<<"D";
                x++;
            }
            else{
                cout<<"R";
                y++;
            }
        }
    }
    else{
        cout<<ans2<<endl;
        ll x=1,y=1;
        while(x!=n || y!=n){
            if(x!=p2[x][y]){
                cout<<"D";
                x++;
            }
            else{
                cout<<"R";
                y++;
            }
        }
    }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/