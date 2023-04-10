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
#define     T               true
#define     F               false
#define     se              second
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     maxi            1000000000000014
#define     mini            -1000000000000014
#define     mod             1000003
#define     an              1000010
#define     maps            map<string,int>
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
int a[6][27],b[6][27];
 
int main()
{
 
    int n,i;
 
    cin>>n;
 
    for(i=0;i<n;i++){
 
        st s;
 
        int j,l;
 
        cin>>s;
 
        l=s.length();
 
        for(j=0;j<l;j++) a[l][s[j]-'A']++;
 
    }
 
    for(i=0;i<n;i++){
 
        st s;
 
        int j,l;
 
        cin>>s;
 
        l=s.length();
 
        for(j=0;j<l;j++) b[l][s[j]-'A']++;
 
    }
 
    int c=0;
 
    for(int j=1;j<=4;j++) for(i=1;i<=26;i++){c+=abs(a[j][i]-b[j][i]);}
 
    cout<<c/2;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/