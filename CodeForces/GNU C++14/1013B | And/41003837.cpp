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
#define     an              100005
#define     maps            map<string,int>
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
ll p[an],q[an],x,y,z;
 
int main()
{
 
    ll n,k;
 
    cin>>n>>k;
 
    ll i,s;
 
    ve a,b;
 
    for(i=0;i<n;i++){
 
        cin>>s;
 
        if(!p[s]) a.pi(s);
 
        p[s]++;
 
    }
 
    if(a.size()!=n){
 
        cout<<0;
        return 0;
 
    }
 
    for(i=0;i<n;i++){
 
        s=(a[i]&k);
 
        if(!q[s]) b.pi(s);
 
        q[s]++;
 
        if(p[s] && a[i]!=s){
 
            cout<<1;
 
            return 0;
 
        }
 
    }
 
    if(b.size()==n){
 
        cout<<-1;
 
        return 0;
 
    }
 
    cout<<2;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/