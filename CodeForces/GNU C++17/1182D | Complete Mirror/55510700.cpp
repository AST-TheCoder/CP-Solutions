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
#define     an              100007
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
 
/*************** #Template FUNCTIONS# **************/
 
/// ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ve a[an];
ll vis[an],d=1,node=1,dis[an],x[an],f,r,par[an],p1,p2,m1,m2,m[an];
 
void bfs(ll s){
    vis[s]=1;
    queue<ll> q;
    q.push(s);
    dis[s]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll i=0;i<a[u].size();i++){
            ll v=a[u][i];
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
                par[v]=u;
                dis[v]=dis[u]+1;
                if(v==m1 || v==m2) m[v]=1;
                else m[v]=m[u];
                if(r==s && a[v].size()==1 && !m[v]){
                    r=v;
                } 
                if(dis[v]>d){
                    d=dis[v];
                    node=v;
                }
                if(x[dis[v]]==-1){
                    x[dis[v]]=a[v].size();
                }
                else if(x[dis[v]]!=a[v].size()) f=1;
            }
        }
    }
}
 
int main()
{
 
    fast;
    
    ll n,i;
    cin>>n;
 
    for(i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a[x].pi(y);
        a[y].pi(x);
    }
 
    bfs(1);
    mem(vis,0);
    mem(dis,0);
    d=1;
 
    p1=node;
 
    bfs(node);
 
    p2=node;
 
    ll root=node;
    for(i=1;i<=d/2;i++){
        m1=root;
        root=par[root];
        m2=par[root];
    }
 
    //cout<<p1<<" "<<root<<" "<<p2<<endl;
 
 
    mem(vis,0);
    mem(dis,0);
    mem(x,-1);
    mem(m,0);
    f=0;
    r=root;
 
    bfs(root);
    //cout<<r<<endl;
 
    if(f){
        root=p1;
        mem(vis,0);
        mem(dis,0);
        mem(x,-1);
        f=0;
 
        bfs(root);
        if(f){
            root=p2;
            mem(vis,0);
            mem(dis,0);
            mem(x,-1);
            f=0;
 
            bfs(root);
            if(f){
                root=r;
                mem(vis,0);
                mem(dis,0);
                mem(x,-1);
                f=0;
 
                bfs(root);
                if(f) cout<<-1<<endl;
                else cout<<root<<endl;
            }
            else cout<<root<<endl;
        }
        else cout<<root<<endl;
    }
    else cout<<root<<endl;
    
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/