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
 
 
ll a[nu],n,k,i,j,r=1,l,p,b[nu],d;
 
int main(){
 
    cin>>p>>k>>l;
 
    n=p*k;
 
    for(i=0;i<n;i++) cin>>a[i];
 
    sort(a,a+n);
 
    //for(i=0;i<n;i++) cout<<a[i]<<" ";
 
    b[1]=a[0];
 
    if(p==1){cout<<b[1];return 0;}
 
    for(i=1,j=2;i<n;i++){
 
        if(b[1]+l<a[i] && r<p){cout<<0;return 0;}
 
        else if(b[1]+l>=a[i]){
 
            b[j]=a[i];
 
            j++;
 
            r++;
 
        }
        else if(b[1]+l<a[i]) break;
 
    }
 
    //for(i=0;i<j;i++) cout<<b[i]<<" ";
 
    for(i=j-1,d=1,r=b[1];;i--){
 
        if(d==p) break;
 
        if(n-i>=(d*k)-1) r+=b[i],d++;
 
    }
 
    cout<<r;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/