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
 
/// ll pc;void PrintCase(){printf("Case #%lli: ",++pc);}
/// ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ll overlap(ll u,ll v,ll x,ll y,ll p,ll q,ll r,ll s)
{
 
    if(v>s || y<q || x<p || u>r) return 0;
    return 1;
 
}
 
int main()
{
 
    ll t;
    cin>>t;
    while(t--){
 
        ll n,m,bl=0,w=0;
        cin>>n>>m;
        ll u,v,x,y;
        ll p,q,r,s;
        cin>>u>>v>>x>>y;
        cin>>p>>q>>r>>s;
 
        bl=(n*m)/2;
        w=(n*m)/2+((n*m)%2!=0);
        //cout<<w<<" "<<b<<endl;
        ll xx,yy;
        xx=x-u+1;
        yy=y-v+1;
 
        if((u%2 && v%2) || (u%2==0 && v%2==0)){
            ll g;
            g=(xx*yy)/2;
            bl-=g;
            w+=g;
        }
        else{
            ll g=(xx*yy)/2+((xx*yy)%2!=0);
            bl-=g;
            w+=g;
        }
//cout<<w<<" "<<b<<endl;
        xx=r-p+1;
        yy=s-q+1;
 
        if((p%2 && q%2) || (p%2==0 && q%2==0)){
            ll g;
            g=(xx*yy)/2+((xx*yy)%2!=0);
            bl+=g;
            w-=g;
        }
        else{
            ll g=(xx*yy)/2;
            bl+=g;
            w-=g;
        }
//cout<<w<<" "<<bl<<endl;
        ll ch=overlap(u,v,x,y,p,q,r,s);
//cout<<ch<<endl;
        if(ch){
            ll a=-1,b=-1,c=-1,d=-1;
            if(u>=p && x<=r && v>=q && y<=s){a=u;b=v;c=x;d=y;}
            else if(p>=u && r<=x && q>=v && s<=y){a=p;b=q;c=r;d=s;}
 
            else if(u>=p && x<=r && y>=s && v<=q) a=u,b=q,c=x,d=s;
            else if(p>=u && r<=x && s>=y && q<=v) a=p,b=v,c=r,d=y;
 
            else if(x>=p && x<=r && y<=s && v>=q) a=p,b=v,c=x,d=y;
            else if(p>=u && p<=x && s<=y && q>=v) a=p,b=q,c=x,d=s;
            else if(v>=q && v<=s && u>=p && x<=r) a=u,b=v,c=x,d=s;
            else if(s>=v && s<=y && p>=u && r<=x) a=p,b=v,c=r,d=s;
 
            else if(u>=p && u<=r && v>=q && y<=s) a=u,b=v,c=r,d=y;
            else if(r>=u && r<=x && q>=v && s<=y) a=u,b=q,c=r,d=s;
            else if(y>=q && y<=s && u>=p && x<=r) a=u,b=q,c=x,d=y;
            else if(q>=v && q<=y && p>=u && r<=x) a=p,b=q,c=r,d=y;
 
            else if(p>=u && p<=x && q>=v && q<=y) a=p,b=q,c=x,d=y;
            else if(r>=u && r<=x && s>=v && s<=y) a=u,b=v,c=r,d=s;
            else if(r>=u && r<=x && q>=v && q<=y) a=u,b=q,c=r,d=y;
            else if(p>=u && p<=x && s>=v && s<=y) a=p,b=v,c=x,d=s;
 
            //cout<<u<<" "<<v<<" "<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            xx=c-a+1;
            yy=d-b+1;
            //cout<<xx<<" "<<yy<<endl;
            if((a%2 && b%2) || (a%2==0 && b%2==0)){
                ll g;
                g=(xx*yy)/2;
                bl+=g;
                w-=g;
            }
            else{
                ll g=(xx*yy)/2+((xx*yy)%2!=0);
                bl+=g;
                w-=g;
            }
        }
 
        cout<<w<<" "<<bl<<endl;
 
    }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/