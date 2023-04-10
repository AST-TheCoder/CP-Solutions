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
#define     ch              char
#define     pairl           pair<ll,ll>
#define     pairs           pair<string,int>
#define     pairi           pair<int,string>
#define     pairss          pair<string,string>
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     fr              first
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     T               true
#define     F               false
#define     se              second
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     maxi            1000000000000014
#define     mini            -1000000000000014
#define     mod             1000000007
#define     an              1000000
#define     maps            map<string,int>
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
ll a[nu],b[nu],c[nu],d[nu],e[nu];
 
int main()
{
    ll n,m,k,p,q;
 
    cin>>n>>m>>k;
 
    ll i;
 
    for(i=1;i<=n;i++) cin>>a[i];
 
    pair<pairl,ll>x[m+1];
 
    for(i=1;i<=m;i++) cin>>x[i].fr.fr>>x[i].fr.se>>x[i].se;
 
    for(i=1;i<=k;i++){
 
        cin>>p>>q;
 
        b[p]++;
 
        b[++q]--;
 
    }
 
    for(i=2,c[1]=b[1];i<=m;i++) c[i]=c[i-1]+b[i];
 
    for(i=1;i<=m;i++) x[i].se*=c[i];
 
    for(i=1;i<=m;i++){
 
        d[x[i].fr.fr]+=x[i].se;
 
        d[++x[i].fr.se]-=x[i].se;
 
    }
 
    for(i=2,e[1]=d[1];i<=n;i++) e[i]=e[i-1]+d[i];
 
    for(i=1;i<=n;i++) a[i]+=e[i];
 
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/