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
#define     an              1000007
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
/// bool sc[an];ve pr;void seieve(){for(ll i=2;i<=an;i++){if(!sc[i]){pr.pi(i);for(ll j=i*i;j<=an;j+=i) sc[j]=1;}}}
/// pairl pf[an];void pri_fact(ll n){for(ll i=0;i<pr.size() && n!=1;i++){pf[i].fr=pr[i];ll c=0;while(!(n%pr[i])){n/=pr[i];c++;}pf[i].se=c;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
vector<pairl> a[an];
ll d[an],p[an],parent;
 
void dijkstra(ll sou)
{
 
    for(ll i=0;i<=100005;i++) d[i]=maxi;
    d[sou]=0;
    p[sou]=sou;
    set<pairl> s;
    s.insert(mp(d[sou],sou));
 
    while(!s.empty()){
        auto t=s.begin();
        ll u=t->se;
        s.erase(t);
        for(ll i=0;i<a[u].size();i++){
            if(d[u]+a[u][i].se<d[a[u][i].fr]){
                d[a[u][i].fr]=d[u]+a[u][i].se;
                s.insert(mp(d[a[u][i].fr],a[u][i].fr));
                p[a[u][i].fr]=u;
            }
        }
    }
 
}
 
int main(int argc, char const *argv[])
{
    fast;
 
    ll n,m,i,x,q,r;
 
    cin>>n>>m;
 
    for(i=0;i<m;i++){
        cin>>x>>q>>r;
        a[x].pi(mp(q,r));
        a[q].pi(mp(x,r));
    }
 
    dijkstra(1);
 
    if(d[n]==maxi){
        cout<<-1;
        return 0;
    }
 
    ve ans;
 
    for(ans.pi(n);n!=1;){
        n=p[n];
        ans.pi(n);
    }
 
    reverse(all(ans));
 
    for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/