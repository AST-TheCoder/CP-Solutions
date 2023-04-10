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
 
mapi m,v;
ll p[an];
 
int main()
{
 
    ll n,i,c=0;
 
    ve s;
 
    cin>>n;
 
    ll a[n],b[n];
 
    for(i=0;i<n;i++){
 
        cin>>a[i]>>b[i];
 
        m[a[i]]++;
        v[b[i]]++;
 
        s.pi(a[i]);
        s.pi(b[i]);
 
    }
 
    sort(all(s));
 
    for(i=0;i<s.size();i++){
 
        if(s[i]!=s[i+1] || i+1==s.size()){
 
            p[m[s[i]]+c]++;
 
            //cout<<p[m[s[i]]+v[s[i]]+c]<<" "<<c<<" "<<m[s[i]]<<" "<<v[s[i]]<<endl;
 
            c+=m[s[i]]-v[s[i]];
 
        }
 
    }
 
    for(i=1,c=0;i<s.size();i++){
 
        if(s[i-1]!=s[i]){
 
            c+=m[s[i-1]]-v[s[i-1]];
 
            p[c]+=s[i]-s[i-1]-1;
 
        }
 
    }
 
    for(i=1;i<=n;i++) cout<<p[i]<<" ";
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/