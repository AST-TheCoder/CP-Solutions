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
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// bool sc[an];ve pr;void sieve(){for(ll i=2;i*i<an;i++){if(!sc[i]){for(ll j=i*i;j<an;j+=i) sc[j]=1;}}pr.pi(2);for(ll i=3;i<an;i+=2) if(!sc[i]) pr.pi(i);}
/// pairl pf[an];void pri_fact(ll n){ll i,u=0;for(i=0;i<pr.size() && n!=1;i++){ll c=0;while(!(n%pr[i])){n/=pr[i];c++;} if(c){pf[u].fr=pr[i];pf[u].se=c;u++;}}if(n>1){pf[u].fr=n;pf[u].se=1;}}
/// ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
 
ll n,q;
ll x[1000007],a[1000007],ran[an*4];
 
void seg(ll node,ll l,ll r)
{
 
    if(l==r){
        ran[node]=x[l];
        return;
    }
    ll right=2*node+1;
    ll left=2*node;
    ll mid=(l+r)/2;
 
    seg(left,l,mid);
    seg(right,mid+1,r);
 
    ran[node]=ran[left]+ran[right];
 
    //cout<<ran[node]<<" "<<node<<" "<<mid<<" "<<endl;
 
}
 
ll que(ll node,ll l,ll r,ll i,ll j)
{
    if(i>r || j<l) return 0;
    if(i<=l && j>=r) return ran[node];
    ll right=2*node+1;
    ll left=2*node;
    ll mid=(l+r)/2;
 
    return que(left,l,mid,i,j)+que(right,mid+1,r,i,j);
 
}
 
int main()
{
 
    in2(n,q);
    st s;
    cin>>s;
    for(ll i=1;i<=n;i++) x[i]=s[i-1]-'0';
    ll p=1,i;
 
    for(i=1,a[0]=0;i<an;i++){
        a[i]=a[i-1]+p;
        a[i]%=mod;
 
        p=(p*2)%mod;
        //cout<<a[i]<<endl;
    }
 
    seg(1,1,n);
 
    while(q--){
        ll l,r;
        in2(l,r);
 
        ll o=que(1,1,n,l,r);
 
        ll z=(r-l+1-o);
 
        out((a[o]*(a[z]+1))%mod);printnl;
 
    }
 
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/