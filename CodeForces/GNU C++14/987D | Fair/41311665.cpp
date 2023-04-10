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
 
ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return(a,a%b);}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
bool sc[an];ve pr;void seieve(){for(ll i=2;i<=an;i++){if(!sc[i]){pr.pi(i);for(ll j=i*i;j<=an;j+=i) sc[j]=1;}}}
pairl pf[an];void pri_fact(ll n){for(ll i=0;i<pr.size() && n!=1;i++){pf[i].fr=pr[i];ll c=0;while(!(n%pr[i])){n/=pr[i];c++;}pf[i].se=c;}}
ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ve a[an];
ll g[an],goods[110],x,c[an];
 
ll BFS(ll n)
{
 
    queue<ll> q;
 
    ll s=1,i,d=0,j=0,r=1,f=1;
 
    goods[g[n]]=1;
 
    c[n]=n;
 
    q.push(n);
 
    while(!q.empty()){
 
        ll u=q.front();
        q.pop();
 
        r--;
 
        if(!r) r+=f,j++,f=0;
 
        for(i=0;i<a[u].size();i++){
 
            if(s==x) return d;
 
            if(c[a[u][i]]!=n){
 
                c[a[u][i]]=n;f++;
 
                q.push(a[u][i]);
 
                if(!goods[g[a[u][i]]]){
 
                    goods[g[a[u][i]]]=1;
 
                    s++;
 
                    d+=j;
 
                }
 
            }
 
        }
 
    }
 
}
 
int main(int argc, char const *argv[])
{
    fast;
 
    ll n,m,k,u,v,i;
 
    cin>>n>>m>>k>>x;
 
    for(i=1;i<=n;i++) cin>>g[i];
 
    for(i=0;i<m;i++){
 
        cin>>u>>v;
 
        a[u].pi(v);
        a[v].pi(u);
 
    }
 
    for(i=1;i<=n;i++){
 
        mem(goods,0);
 
        ll ans=BFS(i);
 
        cout<<ans<<" ";
 
    }
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/