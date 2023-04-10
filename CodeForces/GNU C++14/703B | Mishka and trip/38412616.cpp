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
 
int main(){
 
    ll n,k,i,s,r;
 
    cin>>n>>k;
 
    ll a[n],d,l[k],f;
 
    for(i=0;i<n;i++) cin>>a[i];
 
    for(i=0,s=0;i<n-1;i++) s+=(a[i]*a[i+1]);
 
    for(i=0,r=0;i<n;i++) r+=a[i];
 
    s+=a[0]*a[n-1];
//cout<<r<<" "<<s<<endl;
    for(i=0,f=0;i<k;i++){
 
        cin>>l[i];
 
        d=r-a[l[i]-1];
 
        if(l[i]!=n) d-=a[l[i]];
        else d-=a[0];
 
        if(l[i]-1!=0) d-=a[l[i]-2];
        else d-=a[n-1];
 
        d-=f;
 
        if(i>0 && abs(l[i]-l[i-1])==1) d+=a[l[i-1]-1];
 
        if(l[0]==1 && l[i]==n ) d+=a[0];
 
        f+=a[l[i]-1];
//cout<<d*a[l[i]-1]<<" "<<f-a[l[i]-1]<<endl;
        s+=(d*a[l[i]-1]);
 
    }
 
    cout<<s;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/