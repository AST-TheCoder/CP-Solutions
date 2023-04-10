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
 
    ll n,i,c=1,x;
 
    cin>>n;
 
    ll a[n];
 
    for(i=0;i<n;i++){
 
        cin>>a[i];
 
    }
 
    for(i=1;i<n;i++){
 
        x=abs(a[i]-a[i-1]);
 
        if((c!=1 && c!=x && x!=1) || x==0){
 
            cout<<"NO";
            return 0;
 
        }
 
        else if(x!=1) c=x;
 
    }
 
    //cout<<c<<endl;
 
    for(i=1;i<n;i++){
 
        if((a[i]%c==0 && a[i-1]%c==1 && c!=2) || (a[i]%c==1 && a[i-1]%c==0 && c!=2)){
 
            cout<<"NO";
            return 0;
 
        }
 
        if(c==2){
 
            if((a[i]%4==3 && a[i-1]%4==2) || (a[i]%4==2 && a[i-1]%4==3)){
 
                cout<<"NO";
                return 0;
 
            }
 
            if((a[i]%4==1 && a[i-1]%4==0) || (a[i]%4==0 && a[i-1]%4==1)){
 
                cout<<"NO";
                return 0;
 
            }
 
 
        }
 
    }
 
    cout<<"YES"<<endl;
    cout<<1000000000<<" "<<c;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/