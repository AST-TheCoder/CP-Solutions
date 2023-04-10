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
 
int main()
{
 
    ll i,n,k,c,su,mi=maxi,f,j;
 
    cin>>n>>k;
 
    st s;
 
    cin>>s;
 
    sort(all(s));
 
    for(i=0;i<n;i++){
 
        c=0;su=0;f=0;
 
        for(j=i;j<n;j++){
 
            if(j==i) c++,su+=s[i]-'a'+1;
            else{
 
                if(s[j]==s[j-1]);
                else if(s[j]-s[j-1]==1 && f==0) f=1;
                else{
 
                    su+=s[j]-'a'+1;
                    f=0;
                    c++;
 
                }
 
            }
//cout<<su<<" ";
            if(c==k) break;
 
        }
        //cout<<endl;
 
        if(c==k) mi=min(su,mi);
 
    }
 
    if(mi!=maxi) cout<<mi;
    else cout<<-1;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/