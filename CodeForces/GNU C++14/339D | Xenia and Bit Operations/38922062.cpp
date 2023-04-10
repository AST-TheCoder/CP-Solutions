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
#define     nu              100005
 
ll a[nu*30],t[nu*30],b[nu*30];
 
void init(int node,int i,int j,int r,int n)
{
 
    r++;
 
    if(i==j) {b[node]=a[i];return;}
 
    int left=node*2;
 
    int right=node*2+1;
 
    int mid=(i+j)/2;
 
    init(left,i,mid,r,n);
 
    init(right,mid+1,j,r,n);
 
    if(!(n%2)){
 
        if(!(r%2)) b[node]=b[left]|b[right];
 
        else b[node]=b[left]^b[right];
 
    }
 
    else{
 
        if(!(r%2)) b[node]=b[left]^b[right];
 
        else b[node]=b[left]|b[right];
 
 
    }
 
}
 
void update(int node,int i,int j,int p,ll x,int r,int n)
{
 
    r++;
 
    if(i>p || j<p) return;
 
    if(i==p && j==p){b[node]=x;return;}
 
    int left=node*2;
 
    int right=node*2+1;
 
    int mid=(i+j)/2;
 
    update(left,i,mid,p,x,r,n);
 
    update(right,mid+1,j,p,x,r,n);
 
    if(!(n%2)){
 
        if(!(r%2)) b[node]=b[left]|b[right];
 
        else b[node]=b[left]^b[right];
 
    }
 
    else{
 
        if(!(r%2)) b[node]=b[left]^b[right];
 
        else b[node]=b[left]|b[right];
 
 
    }
}
 
int main()
{
    int n,q,i,j;
 
    cin>>n>>q;
 
    j=pow(2,n);
 
    for(i=1;i<=j;i++){
 
        cin>>a[i];
 
    }
 
    init(1,1,j,0,n);
 
    for(i=1;i<=q;i++){
 
        int x,r;
 
        cin>>x>>r;
 
        update(1,1,j,x,r,0,n);
 
        cout<<b[1]<<endl;
 
    }
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/
 