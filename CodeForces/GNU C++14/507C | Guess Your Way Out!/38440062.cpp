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
 
ll s;
bool i;
 
ll bin_T(ll h,ll n){
 
    ll r=pow(2,h);
 
    if((r/2<n && !i) || (r/2>=n && i)){s+=r-1; i?i=F:i=T;}
 
    i?i=F:i=T;
 
    if(n>r/2) n-=r/2;
 
    h--;
 
    s++;
 
//cout<<s<<" "<<h<<" "<<i<<" "<<r<<" "<<n<<endl;
    if(h==0) return s;
 
    else return bin_T(h,n);
 
}
 
int main(){
 
    ll h,n;
 
    cin>>h>>n;
 
    cout<<bin_T(h,n);
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/