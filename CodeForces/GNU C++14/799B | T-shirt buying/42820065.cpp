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
 
int main(int argc, char const *argv[])
{
    fast;
 
    ll n,i,p,q,r;
 
    cin>>n;
 
    pair<ll,pairl> a[n];
    ve x,y,z;
 
    for(i=0;i<n;i++) cin>>a[i].fr;
    for(i=0;i<n;i++) cin>>a[i].se.fr;
    for(i=0;i<n;i++) cin>>a[i].se.se;
 
    sort(a,a+n);
 
    for(i=0;i<n;i++){
        if(a[i].se.fr==1 || a[i].se.se==1) x.pi(i);
        if(a[i].se.fr==2 || a[i].se.se==2) y.pi(i);
        if(a[i].se.fr==3 || a[i].se.se==3) z.pi(i);
    }
//for(i=0;i<x.size();i++)cout<<x[i]<<" ";cout<<endl;
//for(i=0;i<y.size();i++)cout<<y[i]<<" ";cout<<endl;
//for(i=0;i<z.size();i++)cout<<z[i]<<" ";cout<<endl;
    ll m;
    cin>>m;
 
    ll c[m],f[n]={0};
 
    for(i=0;i<m;i++) cin>>c[i];
 
    for(i=0,p=0,q=0,r=0;i<m;i++){
        if(c[i]==1){
            while(1){
                if(p==x.size()){
                    cout<<-1<<" ";
                    break;
                }
                if(f[x[p]]==0){
                    cout<<a[x[p]].fr<<" ";
                    f[x[p]]=1;
                    p++;
                    break;
                }
                p++;
            }
        }
        if(c[i]==2){
            while(1){
                if(q==y.size()){
                    cout<<-1<<" ";
                    break;
                }
                if(f[y[q]]==0){
                    cout<<a[y[q]].fr<<" ";
                    f[y[q]]=1;
                    q++;
                    break;
                }
                q++;
            }
        }
        if(c[i]==3){
            while(1){
                if(r==z.size()){
                    cout<<-1<<" ";
                    break;
                }
                if(f[z[r]]==0){
                    cout<<a[z[r]].fr<<" ";
                    f[z[r]]=1;
                    r++;
                    break;
                }
                r++;
            }
        }
        //cout<<i<<" "<<c[i]<<" "<<p<<" "<<q<<" "<<r<<endl;
    }
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/