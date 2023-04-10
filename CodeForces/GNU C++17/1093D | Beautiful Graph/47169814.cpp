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
#define     an              300007
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
 
ve a[an];
ll b[an],n,m,xx=0,f,ans,ans1,ans2,p2[an];
queue<ll>q;
 
void BFS(ll source)
{
 
    q.push(source);
    b[source]=1;
    ans1=2;ans2=1;
 
    while(!q.empty()){
 
        ll u=q.front();
        q.pop();
        xx=0;
        ll ck=0;
 
        for(ll i=0;i<a[u].size();i++){
 
            if(b[a[u][i]]==-1){
 
                b[a[u][i]]=b[u]+1;
                q.push(a[u][i]);
                ck++;
 
            }
            else if(b[u]%2==b[a[u][i]]%2) f=1;
 
        }
        //cout<<ck<<endl;
 
        if(ck){
            //cout<<"P"<<" "<<b[u]<<" "<<ck<<endl;
            if(b[u]%2==0) ans1=(ans1*p2[ck])%mod;
            else ans2=(ans2*p2[ck])%mod;
 
        }
        //cout<<ans1<<" "<<ans2<<endl;
 
    }
 
}
 
int main()
{
    p2[0]=1;
    for(ll i=1;i<an;i++){
        p2[i]=(p2[i-1]*2)%mod;
    }
 
    ll t;
    cin>>t;
    
    while(t--){
 
        cin>>n>>m;
        f=0,xx=0;
        ll i;
        ans=1;
        for(ll i=1;i<=n;i++) b[i]=-1;
        for(i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            a[x].pi(y);
            a[y].pi(x);
        }
 
        for(i=1;i<=n;i++){
            if(b[i]==-1){
                f=0;
                BFS(i);
                ans*=(ans1+ans2)%mod;
                ans%=mod;
                if(f){
                    cout<<0<<endl;
                    goto read;
                }
            }
        }
 
        cout<<ans<<endl;
        read:
        for(i=1;i<=n;i++){
            a[i].clear();
            b[i]=-1;
        }
 
    }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/