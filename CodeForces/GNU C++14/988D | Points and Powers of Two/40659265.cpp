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
#define     ll              long long int
#define     ul              unsigned long long int
#define     dob             double
#define     st              string
#define     cha             char
#define     pairl           pair<ll,ll>
#define     pairs           pair<string,int>
#define     pairi           pair<int,string>
#define     pairss          pair<string,string>
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     fr              first
#define     se              second
#define     T               true
#define     F               false
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     maxi            1000000000000014
#define     mini            -100000000000014
#define     mod             1000000007
#define     an              2000005
#define     maps            map<string,int>
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
mapi m;
 
ll a[31];
 
int main()
{
 
    ll i,j,u,v,x;
    u=v=x=maxi;
 
    for(i=0;i<=30;i++){
 
        a[i]=pow(2,i);
 
    }
 
    ll n;
 
    cin>>n;
 
    ll p[n];
 
    for(i=0;i<n;i++){
 
        cin>>p[i];
 
        m[p[i]]=1;
 
    }
 
    sort(p,p+n);
 
    if(n==1){
 
        cout<<1<<endl<<p[0];
        return 0;
 
    }
 
    else if(n==2){
 
        x=abs(p[0]-p[1]);
 
        for(i=0;i<=30;i++) if(x==a[i]){
 
            cout<<2<<endl<<p[0]<<" "<<p[1];
            return 0;
 
        }
 
        cout<<1<<endl<<p[0];
        return 0;
 
    }
 
    for(i=0;i<n;i++){
 
        for(j=0;j<=30;j++){
 
            if(m[p[i]+a[j]]==1){
                v=p[i]+a[j];
                u=p[i];
                if(m[p[i]+(2*a[j])]==1){
 
                    x=p[i]+2*a[j];
                    break;
 
                }
 
            }
 
        }
 
        if(x!=maxi) break;
 
    }
 
    if(u==maxi) cout<<1<<endl<<p[0];
    else if(x==maxi) cout<<2<<endl<<u<<" "<<v;
    else cout<<3<<endl<<u<<" "<<v<<" "<<x;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/