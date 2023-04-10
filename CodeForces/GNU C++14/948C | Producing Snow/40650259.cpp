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
 
ll br[an],ans[an],idx,Te[an],x,c;
 
int main()
{
 
    ll n,i;
 
    cin>>n;
 
    ll a[n],t[n];
 
    for(i=0;i<n;i++) cin>>a[i];
 
    for(i=0;i<n;i++){
 
        cin>>t[i];
 
        if(!i) Te[i]=t[i];
 
        else Te[i]=Te[i-1]+t[i];
 
    }
 
    for(i=0;i<n;i++){
 
        ll start=i,ends=n-1,mid;
 
        while(start<=ends){
 
            ll mid=(start+ends)/2;
 
            if(Te[mid]-x>=a[i]) ends=mid-1;
            else start=mid+1;
 
        }
 
        idx=ends;
 
        //cout<<ends<<" ";
 
        if(idx>=0) br[idx]++;
 
        ans[idx+1]+=a[i]-(Te[idx]-x);
 
        x+=t[i];
 
    }
//cout<<endl;
 
    if(a[0]<=t[0]) c=0;
    else c=1;
 
    for(i=0;i<n;i++,c++){
 
        //cout<<br[i]<<" "<<ans[i]<<" ";
 
        ans[i]+=(c*t[i]);
 
        c-=br[i];
 
        cout<<ans[i]<<" ";
 
    }
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/