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
#define     an              45000
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
/*************** #Template FUNCTIONS# **************/
 
ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(a,a%b);}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
bool sc[an];ve pr;void seieve(){for(ll i=2;i<=an;i++){if(!sc[i]){pr.pi(i);for(ll j=i*i;j<=an;j+=i) sc[j]=1;}}}
pairl pf[an];void pri_fact(ll n){for(ll i=0;i<pr.size() && n!=1;i++){pf[i].fr=pr[i];ll c=0;while(!(n%pr[i])){n/=pr[i];c++;}pf[i].se=c;}}
ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
int main(int argc, char const *argv[])
{
 
    fast;
 
    st s;
 
    ll m=1,i;
 
    cin>>s;
 
    ll l=s.size(),c=1;
 
    if(s[0]!=s[l-1]){
 
        ll a=1,b=1;
 
 
        for(i=1;i<l;i++){
 
            if(s[i]==s[i-1]) break;
 
            a++;
 
        }
 
        if(i!=l){
 
            for(i=l-2;i>=0;i--){
 
                if(s[i]==s[i+1]) break;
 
                b++;
 
            }
 
        }
 
        else b=0;
 
        m=a+b;
 
    }
//cout<<m<<endl;
    for(i=1;i<l;i++){
 
        if(s[i]!=s[i-1]){
 
            c++;
 
        }
 
        else{
 
            m=max(m,c);
//cout<<m<<" "<<i<<endl;
            c=1;
 
        }
//cout<<i<<" "<<m<<" "<<c<<endl;
    }
 
    cout<<max(m,c);
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/