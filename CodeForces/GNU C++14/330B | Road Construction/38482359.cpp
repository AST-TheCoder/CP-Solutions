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
#define     nu              1000005
 
 
int c[1005];
 
int main(){
 
    int n,m;
 
    cin>>n>>m;
 
    int a,b,i,d;
 
    for(i=0;i<m;i++){
 
        cin>>a>>b;
 
        c[a]++;
        c[b]++;
 
    }
 
    for(i=1;i<=n;i++) if(!c[i]){d=i;break;}
 
    cout<<n-1<<endl;
 
    for(i=1;i<=n;i++){
 
        if(i==d) continue;
 
        else cout<<d<<" "<<i<<endl;
 
    }
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/