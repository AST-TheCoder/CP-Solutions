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
#define     an              2000000
#define     maps            map<string,int>
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
int main()
{
    fast;
 
    ll n,k;
 
    scanf("%lli",&n);
 
    for(k=0;k<n;k++){
 
        ll a,b;
        scanf("%lli %lli",&a,&b);
 
        ll m=a*b;
        ll s=sqrt(sqrt(m)),f,i,q=-1,mi,fl=0;
        if(sqrt(m)<1000001) f=sqrt(m);
        else f=1000001;
 
        while(s<=f){
 
            mi=(s+f)/2;
            if(mi>1000001){
                f=1000001;
                continue;
            }
            //cout<<mi<<" ";
            if(mi*mi*mi==m){q=mi;break;}
            else if(mi*mi*mi>m) f=mi-1;
            else s=mi+1;
 
        }
//cout<<q<<" ";
        if(q!=-1 && a%q==0 && b%q==0)printf("Yes\n");
        else printf("No\n");
 
    }
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/