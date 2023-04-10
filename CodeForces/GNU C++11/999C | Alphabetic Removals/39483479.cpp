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
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
ll a[27],b[27];
 
int main()
{
    fast;
 
    ll n,k,i,j=0,c=0,d;
 
    cin>>n>>k;
 
    st s;
 
    cin>>s;
 
    for(i=0;i<n;i++){
 
        a[s[i]-'a']++;
 
    }
 
    for(i=0;i<27;i++){
 
        c+=a[i];
 
        if(c>k){
            c-=a[i];
            b[i]=k-c;
            break;
        }
 
        b[i]=a[i];
    }
 
    for(i=0;i<n;i++){
 
        if(b[s[i]-'a']!=0) b[s[i]-'a']--,k--;
 
        else{
 
            cout<<s[i];
 
        }
 
    }
 
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/