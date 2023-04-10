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
 
ve b,a[an],ts;
bool c[an];
ll u,v;
 
void DFS(ll source,ll x)
{
 
    c[source]=T;
 
    for(ll i=0;i<a[source].size();i++){
 
        if(a[source][i]==x) c[a[source][i]]=T;
 
        else if(c[a[source][i]]==F){
 
            DFS(a[source][i],x);
 
        }
 
    }
    ts.pi(source);
    return;
 
}
 
int main()
{
 
    ll n,vi,ui,x,mi=0;
 
    cin>>n>>u>>v;
 
    for(ll i=1;i<n;i++){
 
        ll p,q;
 
        cin>>p>>q;
 
        a[p].pi(q);
        a[q].pi(p);
 
    }
 
    DFS(v,u);
 
    vi=ts.size();
 
    ts.clear();
 
    mem(c,0);
 
    DFS(u,v);
 
    ui=ts.size();
 
    mi=ui+vi-n;
 
    ll ans=((n*(n-1))/2)+((vi*(vi-1))/2)+((ui*(ui-1))/2)-((mi*(mi-1))/2);
 
    cout<<ans;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/