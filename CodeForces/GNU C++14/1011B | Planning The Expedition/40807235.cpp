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
 
int b[1000];
ve x;
 
int main()
{
 
    ll n,m,ma=0,c;
 
    cin>>n>>m;
 
    ll i,a[m],j,k;
 
    for(i=0;i<m;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(i=0;i<=100;i++){
 
        if(b[i]!=0) x.pi(b[i]);
 
    }
 
    sort(all(x));
 
    ll s=x.size();
 
    for(i=0;i<s;i++){
 
        ll v=x[i];
        c=0;
 
        for(j=i;j<s && v;j++){
 
            c+=x[j]/v;
 
            if(j+1==s && c<n){
 
                v--;c=0;j=i-1;
                //cout<<v<<" ";
 
            }
 
        }
 
        if(c>=n) ma=max(ma,v);
 
    }
 
    cout<<ma;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/