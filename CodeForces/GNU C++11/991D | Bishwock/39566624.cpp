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
 
 
int main()
{
 
    st a,b,p,q;
 
    cin>>a>>b;
 
    p=a;q=b;
 
    int l=a.length(),c=0;
 
    for(int i=0;i<l;i++){
 
        if(p[i]=='0' && p[i+1]=='0' && q[i]=='0'){
 
            c++;
            p[i]='x';
            p[i+1]='x';
            q[i]='x';
 
        }
        else if(p[i]=='0' && q[i+1]=='0' && q[i]=='0'){
 
            c++;
            p[i]='x';
            q[i]='x';
            q[i+1]='x';
 
        }
 
        else if(q[i]=='0' && q[i+1]=='0' && p[i+1]=='0'){
 
            c++;
            q[i]='x';
            q[i+1]='x';
            p[i+1]='x';
 
        }
 
        else if(q[i+1]=='0' && p[i]=='0' && p[i+1]=='0'){
 
            c++;
            p[i]='x';
            p[i+1]='x';
            q[i+1]='x';
 
        }
 
    }
 
    cout<<c;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/