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
#define     an              200005
#define     maps            map<string,int>
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
int main()
{
 
    int n,m,i;
 
    cin>>n>>m;
 
    set<ll> s;
 
    for(i=0;i<m;i++) s.insert(i);
 
    ll a[n];
 
    int k=n/m;
 
    int c[m]={0};
 
    ll ans=0;
 
    for(i=0;i<n;i++){
        cin>>a[i];
 
        auto j=s.lower_bound(a[i]%m);
 
        if(j==s.end()) j=s.begin();
 
        ll step;
 
        if(*j<a[i]%m){
            step=m-(a[i]%m)+*j;
        }
 
        else step=*j-(a[i]%m);
 
        if(c[*j]+1==k) s.erase(j);
 
        else c[*j]++;
 
        a[i]+=step;
 
        ans+=step;
    }
 
    cout<<ans<<endl;
 
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/