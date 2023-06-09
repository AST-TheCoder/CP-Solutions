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
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     in              scanf
#define     out             printf
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
 
ll pc;void PrintCase(){out("Case %lli: ",++pc);}
ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return(a,a%b);}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
bool sc[an];ve pr;void seieve(){for(ll i=2;i<=an;i++){if(!sc[i]){pr.pi(i);for(ll j=i*i;j<=an;j+=i) sc[j]=1;}}}
pairl pf[an];void pri_fact(ll n){for(ll i=0;i<pr.size() && n!=1;i++){pf[i].fr=pr[i];ll c=0;while(!(n%pr[i])){n/=pr[i];c++;}pf[i].se=c;}}
ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ll pow_t[41],c;
 
int main()
{
 
    ll n,q;
 
    cin>>n>>q;
 
    ll a[n],b,i,j,pt;
 
    for(i=0;i<n;i++){
 
        cin>>a[i];
 
        pt=log2(a[i]);
 
        pow_t[pt]++;
 
    }
 
    for(i=0;i<q;i++){
 
        cin>>b;
 
        for(j=40,c=0;j>=0 && b;j--){
 
            if(pow_t[j]){
 
                ll x=pow(2,j);
 
                ll s=x*pow_t[j];
 
                if(s<=b){
 
                    b-=s;
 
                    c+=pow_t[j];
 
                }
 
                else{
 
                    c+=b/x;
 
                    b%=x;
 
                }
 
            }
 
        }
 
        if(!b) cout<<c<<nl;
        else cout<<-1<<nl;
 
    }
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/