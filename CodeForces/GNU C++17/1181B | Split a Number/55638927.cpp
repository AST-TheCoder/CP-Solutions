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
st s;
ve x;
ll l;
 
void add(ll p)
{
    ll q=0,i,j;
    for(i=p,j=l-1;i>=0 && j>p;i--,j--){
        ll y=s[i]-'0'+s[j]-'0'+q;
        //cout<<y<<" "<<i<<" "<<j<<endl;
        x.pi(y%10);
        q=y/10;
    }
    //if(l%2){
        if(i>=0){
            while(i!=-1){
                //cout<<i<<" "<<s[i]<<endl;
                ll y=s[i]-'0'+q;
                x.pi(y%10);
                q=y/10;
                i--;
            }
        }
        else{
            while(j!=p){
                ll y=s[j]-'0'+q;
                x.pi(y%10);
                q=y/10;
                j--;
            }
        }
    //}
 
    if(q) x.pi(q);
    for(i=x.size();i<an;i++) x.pi(0);
    reverse(all(x));
}
 
int main()
{
 
    fast;
 
    cin>>l>>s;
    ll p=l/2,i,f=0;
    ve ans;
 
    if(s[p]=='0'){
        for(i=p;i<l;i++) if(s[i]!='0') break;
            //cout<<i<<endl;
        add(i-1);
        ve a=x;
        x.clear();
        for(i=p;i>=0;i--) if(s[i]!='0') break;
        //cout<<i<<endl;
        add(i-1);
        ve b=x;
        for(i=0;i<an;i++){
            if(a[i]<b[i]){
                //cout<<a[i]<<" "<<i<<endl;
                ans=a;
                break;
            }
            else if(a[i]>b[i]){
                ans=b;
                break;
            }
        }
        if(i==an){
            ans=x;
        }
    }
 
    else if(l%2){
        add(p);
        ve a=x;
        x.clear();
        add(p-1);
        ve b=x;
        for(i=0;i<an;i++){
            if(a[i]<b[i]){
                ans=a;
                break;
            }
            else if(a[i]>b[i]){
                ans=b;
                break;
            }
        }
        if(i==an){
            ans=x;
        }
    }
    else{
        add(p-1);
        ans=x;
    }
 
    for(i=0;i<an;i++){
        if(ans[i]!=0) f=1;
        if(f){
            cout<<ans[i];
        }
    }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/