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
#define     mod             998244353
#define     an              200007
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
 
ve x[an],v,r;
priority_queue<pairl> q;
ll c[an],ch[an];
 
int main()
{
    fast;
 
    ll n,i;
    cin>>n;
 
    ll a[n],b[n];
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        x[a[i]].pi(b[i]);
        c[a[i]]=max(c[a[i]],b[i]);
    }
 
    for(i=1;i<=n;i++){
        q.push(mp(c[i],i));
    }
 
    ll t;
    cin>>t;
    while(t--){
        ll k,u=0,vv=0,idx=0;
        cin>>k;
        for(i=0;i<k;i++){
            ll xx;
            cin>>xx;
            v.pi(xx);
            ch[xx]=1;
        }
        pairl p;
        for(i=0;i<q.size();i++){
            p=q.top();
            if(ch[p.se]){
                q.pop();
                i--;
                r.pi(p.se);
            }
            else if(u==0){
                u=p.fr;
                idx=p.se;
                i--;
                q.pop();
                r.pi(p.se);
            }
            else{
                vv=p.fr;
                break;
            }
        }
        if(u==0){
            cout<<0<<" "<<0<<endl;
        }
        else{
            ll low=0,high=x[idx].size()-1,mid;
            while(low+1<high){
                mid=(low+high)/2;
                if(x[idx][mid]>vv) high=mid;
                else low=mid;
            }
            ll ans;
            if(x[idx][low]>vv) ans=x[idx][low];
            else ans=x[idx][high];
            cout<<idx<<" "<<ans<<endl;
        }
        for(i=0;i<v.size();i++){
            ch[v[i]]=0;
        }
        v.clear();
        for(i=0;i<r.size();i++){
            q.push(mp(c[r[i]],r[i]));
        }
        r.clear();
    }
 
    End;
}
/*****************  ALHAMDULILLAH  *****************/