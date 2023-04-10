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
#define     T               true
#define     F               false
#define     se              second
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     maxi            1000000000000014
#define     mini            -1000000000000014
#define     mod             1000003
#define     an              1000010
#define     maps            map<string,int>
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
ll a[nu],off[nu],on[nu],n,dp[nu];
 
int main()
{
 
    ll m,i;
 
    cin>>n>>m;
 
    for(i=1;i<=n;i++) cin>>a[i];
    a[i]=m;
 
    if(n%2==1){
 
        off[n]=a[n+1]-a[n];
 
        on[n-1]=a[n]-a[n-1];
 
        off[n-1]=off[n];
 
        for(i=n-2;i>=0;i--){
 
            if(i%2==1) off[i]=a[i+1]-a[i]+off[i+1],on[i]=on[i+1];
 
            else on[i]=a[i+1]-a[i]+on[i+1],off[i]=off[i+1];
 
        }
 
    }
 
    if(n%2==0){
 
        on[n]=a[n+1]-a[n];
 
        off[n-1]=a[n]-a[n-1];
 
        on[n-1]=on[n];
 
        for(i=n-2;i>=0;i--){
 
            if(i%2==0) on[i]=a[i+1]-a[i]+on[i+1],off[i]=off[i+1];
 
            else off[i]=a[i+1]-a[i]+off[i+1],on[i]=on[i+1];
 
        }
 
    }
 
    ll p=on[0],q=off[0],c=p;
 
    for(i=0;i<=n;i++){
 
        if(a[i+1]-a[i]>1){
 
            dp[i]=p-on[i]+off[i];
 
        }
 
        c=max(dp[i],c);
 
    }
 
    cout<<(c==p?c:c-1);
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/