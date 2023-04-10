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
/// ll GCD(ll a,ll b){if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return(b,a%b);}
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
 
    ll n;
    cin>>n;
 
    ll a[n+1],b=0,c=maxi,p=maxi,ind3,ind1,ind2,i,x,y,l;
 
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(b<=a[i]){
            if(b==a[i]) x++;
            else x=1;
            b=a[i];
            ind1=i;
        }
 
        if(c>=a[i]){
            if(c==a[i]) y++;
            else y=1;
            p=c;
            c=a[i];
            ind3=ind2;
            ind2=i;
        }
    }
 
    if(p==maxi){
        for(i=1,p=maxi;i<=n;i++){
            if(i==ind2) continue;
            if(a[i]==c) l=i;
            else if(a[i]<b){
                p=a[i];
                ind3=i;
            }
        }
    }
 
    if(p==maxi){
        p=c;
        ind3=l;
    }
//cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;
    if(n==1 || n==2 || b==c){
        cout<<-1;
        End;
    }
 
    if(x+1==n){
        if(n==3 && ind2==2){
            cout<<-1;
            End;
        }
        if(ind2==n || ind2==n-1) cout<<ind2-1<<" "<<ind2;
        else cout<<ind2<<" "<<ind2+1;
        End;
    }
 
    else{
        if(n==3){
            if(ind1==2){
                if(a[1]==a[3]) cout<<-1;
                else cout<<ind1<<" "<<ind2;
                End;
            }
 
            else cout<<ind1<<" "<<2;
 
            End;
        }
 
        if(ind2>ind1 && ind3>ind1){
            cout<<ind1<<" "<<min(ind2,ind3);
            End;
        }
        else if(ind2<ind1 && ind3<ind1){
            cout<<ind1<<" "<<max(ind2,ind3);
            End;
        }
 
        else{
            if(a[ind2]!=a[ind3]){
                cout<<ind1<<" "<<ind2;
                End;
            }
            else{
                if(y+x==n){
                    if(ind2!=1 && ind2!=n) cout<<ind1<<" "<<ind2;
                    else cout<<ind1<<" "<<ind3;
                    End;
                }
                else{
                    for(i=1;i<=n;i++){
                        if(a[i]>c && a[i]!=b) break;
                    }
                    cout<<ind1<<" "<<i;
                }
            }
        }
 
    }
 
 
 End;
}
/*****************  ALHAMDULILLAH  *****************/