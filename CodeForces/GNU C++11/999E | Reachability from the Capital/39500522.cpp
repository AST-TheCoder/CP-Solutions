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
 
ve b,a[10000],ts;
int t;
bool c[10000];
 
void DFS(int source)
{
 
    c[source]=T;
 
    for(int i=0;i<a[source].size();i++){
 
        if(c[a[source][i]]==F){
 
            DFS(a[source][i]);
 
        }
 
    }
 
    ts.pi(source);
    return;
 
}
 
void DFS1(int source)
{
 
    c[source]=T;
 
    for(int i=0;i<a[source].size();i++){
 
        if(c[a[source][i]]==F){
 
            DFS1(a[source][i]);
 
        }
 
    }
 
    return;
 
}
 
int main()
{
 
    int n,m,s;
 
    cin>>n>>m>>s;
 
    for(int i=0;i<m;i++){
 
        int p,q;
 
        cin>>p>>q;
 
        if(q!=s) a[p].pi(q);
 
    }
 
    for(int i=0;i<=n;i++) b.pi(i);
 
    DFS(s);
 
    for(int i=1;i<b.size();i++) if(c[b[i]]==F) DFS(b[i]);
 
    reverse(all(ts));
 
    int r=0;
 
    memset(c,0,sizeof(c));
 
    for(int i=0;i<ts.size();i++){
 
        if(ts[i]==s) break;
 
        if(c[ts[i]]==F){
 
            DFS1(ts[i]);
            r++;
 
        }
 
    }
 
    cout<<r;
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/