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
 
map<ll,ll> a;
 
int main()
{
 
    ll p[50],i,n,x,c=0,f,j;
 
    for(i=0;i<50;i++) p[i]=pow(2,i);
    //for(i=0;i<50;i++) cout<<p[i]<<" ";
 
    cin>>n;
 
    ll m[n];
 
    for(i=0;i<n;i++){
 
        cin>>x;
 
        m[i]=x;
 
        a[x]++;
 
    }
 
    for(i=0;i<n;i++){
 
        f=0;
 
        for(j=0;j<50;j++){
 
            if(m[i]<p[j]){
 
                x=p[j]-m[i];
 
                //cout<<x<<" ";
 
                if(a[x]!=0 && (x!=m[i] || (x==m[i] && a[x]>1))){
 
                    f=1;
                    break;
 
                }
 
            }
 
        }
//cout<<endl;
        if(!f) c++;
 
    }
 
    cout<<c;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/