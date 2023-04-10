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
#define     nu              200005
 
int main() {
 
    int n;
 
    cin>>n;
 
    int i;
 
    pairi s[n];
 
    st t;
 
    int k,j;
 
    for(i=0;i<n;i++){
 
        cin>>s[i].se;
 
        s[i].fr=s[i].se.length();
 
    }
 
    sort(s,s+n);
 
    for(i=0;i<n-1;i++){
 
        int d=s[i].fr;
 
        for(j=0;j<=s[i+1].fr-d;j++){
 
            if(s[i+1].se.substr(j,d)==s[i].se) break;
 
            else if(j==s[i+1].fr-d){
 
                cout<<"NO";
 
                return 0;
 
            }
 
        }
 
    }
 
    cout<<"YES"<<endl;
 
    for(i=0;i<n;i++){
 
        cout<<s[i].se<<endl;
 
    }
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/