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
#define     an              1000000
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
 
ll n,x1[an],y1[an],x2[an],y2[an],x=maxi,y=maxi;
 
ll check(ll start,ll r_l,ll match)
{
 
    if(match==start) start++;
 
    ll i=start;
 
    ll ax=x1[i],ay=y1[i],bx=x2[i],by=y2[i];
//cout<<endl;
    for(;i>=0 && i<n;){
//cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
        if(match==i || i==start) goto read;
        if(ax>=x1[i] && ay>=y1[i] && bx<=x2[i] && by<=y2[i]) goto read;
 
        if(ax<=x1[i] && ay<=y1[i] && bx>=x2[i] && by>=y2[i]){
 
            ax=x1[i],ay=y1[i],bx=x2[i],by=y2[i];
            goto read;
 
        }
        if(x2[i]>=ax && x1[i]<=bx && y2[i]>=ay && y1[i]<=by){
 
            if(x2[i]<=bx && x1[i]<=ax){
 
                if(y1[i]<=ay && y2[i]<=by){
                    bx=x2[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]>=by){
                    ay=y1[i],bx=x2[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]<=by){
                    ay=y1[i],bx=x2[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]<=ay && y2[i]>=by){
                    bx=x2[i];
                    goto read;
                }
 
            }
 
            if(x2[i]>=bx && x1[i]>=ax){
 
                if(y1[i]<=ay && y2[i]<=by){
                    ax=x1[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]>=by){
                    ax=x1[i],ay=y1[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]<=by){
                    ay=y1[i],ax=x1[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]<=ay && y2[i]>=by){
                    ax=x1[i];
                    goto read;
                }
 
            }
 
            if(x1[i]>=ax && x2[i]<=bx){
 
                if(y1[i]<=ay && y2[i]>=by){
                    ax=x1[i],bx=x2[i];
                    goto read;
                }
 
                if(y1[i]<=ay && y2[i]<=by){
                    ax=x1[i],bx=x2[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]>=by){
                    ax=x1[i],bx=x2[i],ay=y1[i];
                    goto read;
                }
 
            }
 
            if(x1[i]<=ax && x2[i]>=bx){
 
                if(y1[i]>=ay && y2[i]<=by){
                    ay=y1[i],by=y2[i];
                    goto read;
                }
 
                if(y1[i]<=ay && y2[i]<=by){
                    by=y2[i];
                    goto read;
                }
 
                if(y1[i]>=ay && y2[i]>=by){
                    ay=y1[i];
                    goto read;
                }
 
            }
 
        }
 
        break;
        read:
        r_l?i--:i++;
 
    }
 
//cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
    x=ax,y=ay;
 
    return i;
 
}
 
int main(int argc, char const *argv[])
{
 
    fast;
 
    cin>>n;
 
    for(ll i=0;i<n;i++) cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
 
    ll r_idx=check(0,0,-1);
    ll l_idx=check(n-1,1,n);
    ll ans=check(0,0,l_idx);
//cout<<r_idx<<" "<<l_idx<<" "<<ans<<endl;
    if(ans==n){cout<<x<<" "<<y;End;}
 
    ans=check(0,0,r_idx);
 
    if(ans==n) cout<<x<<" "<<y;
 
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/