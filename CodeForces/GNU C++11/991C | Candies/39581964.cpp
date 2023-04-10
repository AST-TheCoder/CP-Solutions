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
#define     cha              char
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
 
ll n,i,s,ch,a;
 
ll bin_search(ll ch,ll n){
 
    ll start=1,finish=n;
 
    ll mid;
 
    ll p;
 
    while(start<=finish){
 
        s=0;
 
        mid=(start+finish)/2;
 
        p=n;
 
        while(p>0){
 
            if(p>mid){
 
                s+=mid;
 
                p-= mid;
 
            }
 
   else{
 
                s+=p;
 
                p=0;
 
   }
   p-=(p/10);
 
        }
 
        if(s>=ch){
 
            finish=mid-1;
 
            a=mid;
 
        }
 
        else start=mid+1;
 
    }
 
    return a;
 
}
 
int main()
{
 
    cin>>n;
 
    if(n%2) ch++;
 
    ch+=n/2;
 
    cout<<bin_search(ch,n);
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/
 