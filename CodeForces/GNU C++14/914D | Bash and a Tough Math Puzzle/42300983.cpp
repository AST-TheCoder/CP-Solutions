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
 
ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else GCD(b,a%b);}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
bool sc[an];ve pr;void seieve(){for(ll i=2;i<=an;i++){if(!sc[i]){pr.pi(i);for(ll j=i*i;j<=an;j+=i) sc[j]=1;}}}
pairl pf[an];void pri_fact(ll n){for(ll i=0;i<pr.size() && n!=1;i++){pf[i].fr=pr[i];ll c=0;while(!(n%pr[i])){n/=pr[i];c++;}pf[i].se=c;}}
ve de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pi(i);de.pi(n%i);}}if((i-1)*(i-1)==n) de.pi(i-1);sort(all(de));}
 
/********************** START **********************/
ll a[an],b[an*30];
 
void init(ll node,ll i,ll j)
{
 
    if(i==j) {b[node]=a[i];return;}
 
    ll left=node*2;
 
    ll right=node*2+1;
 
    ll mid=(i+j)/2;
 
    init(left,i,mid);
 
    init(right,mid+1,j);
 
    b[node]=GCD(b[left],b[right]);
 
}
 
ll f;
ll query(ll node,ll i,ll j,ll p,ll q,ll x)
{
 
    if(i>q || j<p || f>1) return 0;
 
    if(i==j){
        if(!(b[node]%x)) return x;
        else{
            f++;
            return 0;
        }
    }
 
    if(i>=p && j<=q && !(b[node]%x)) return x;
 
    ll left=node*2;
 
    ll right=node*2+1;
 
    ll mid=(i+j)/2;
 
    ll p1=query(left,i,mid,p,q,x);
 
    if(f>1) return 0;
 
    ll p2=query(right,mid+1,j,p,q,x);
 
    return GCD(p1,p2);
 
}
 
void update(ll node,ll i,ll j,ll p,ll x)
{
 
    if(i>p || j<p) return;
 
    if(i==p && j==p){b[node]=x;return;}
 
    ll left=node*2;
 
    ll right=node*2+1;
 
    ll mid=(i+j)/2;
 
    update(left,i,mid,p,x);
 
    update(right,mid+1,j,p,x);
 
    b[node]=GCD(b[left],b[right]);
 
}
 
int main(int argc, char const *argv[])
{
 
    fast;
 
    ll n,i;
 
    cin>>n;
 
    for(i=1;i<=n;i++) cin>>a[i];
 
    init(1,1,n);
 
    ll q;
    //for(i=1;i<=6;i++) cout<<b[i]<<" ";cout<<endl;
 
    cin>>q;
 
    while(q--){
 
        ll x;
        cin>>x;
 
        if(x==1){
            ll l,r,g;
            f=0;
            cin>>l>>r>>g;
            ll ok=query(1,1,n,l,r,g);
//cout<<ok<<" "<<f<<endl;
            if(f<=1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
 
        else{
            ll in,u;
            cin>>in>>u;
 
            update(1,1,n,in,u);
            //for(i=1;i<=6;i++) cout<<b[i]<<" ";cout<<endl;
        }
 
    }
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/